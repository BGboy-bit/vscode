const express = require('express');
const { exec } = require('child_process');
const net = require('net');
const app = express();

app.use(express.json());

const portInUse = new Set(); // 维护一个集合存储正在检查或使用的端口

function checkPort(port) {
 return new Promise((resolve, reject) => {
   if (portInUse.has(port)) { // 如果端口已经在检查中，则直接拒绝
     reject(new Error(`Port ${port} is already being checked or used.`));
   } else {
     portInUse.add(port); // 标记端口为正在检查
     const server = net.createServer();
     server.listen(port, () => {
       server.once('close', () => {
         portInUse.delete(port); // 清除标记
         resolve(port);
       });
       server.close();
     });
     server.on('error', (err) => {
       portInUse.delete(port); // 发生错误时，清除标记
       reject(err);
     });
   }
 });
}

async function findFreePort(startPort) {
 let currentPort = startPort;
 while (true) {
   try {
     const freePort = await checkPort(currentPort);
     return freePort;
   } catch (error) {
     currentPort++;
   }
 }
}

async function deployCodeServer(email) {
   const startPort = 10000;
   try {
       const freePort = await findFreePort(startPort);
       const containerName = `coder-${freePort}`;
       const imageName = 'codercom/code-server';
       const command = `docker run -d -p ${freePort}:8080 -e PASSWORD="${email}" --name ${containerName} ${imageName}`;
       exec(command, (error, stdout, stderr) => {
           if (error) {
               console.error(`执行错误: ${error}`);
               throw new Error(`部署错误: ${error.message}`);
           }
           console.log(`服务器运行在 http://localhost:${freePort}`);
           return freePort;
       });
   } catch (error) {
       throw new Error(`寻找空闲端口错误: ${error.message}`);
   }
}

app.post('/deploy', express.urlencoded({ extended: true }), (req, res) => {
   console.log(`正在获取邮箱...`);
   const email = req.body.field3; // 假设 'field3' 是表单中邮箱字段的名字
   console.log(`获取到邮箱 ${email}`);
   // 你可以在这里调用 deploy 逻辑或者存储邮箱值以便稍后使用
   deployCodeServer(email)
       .then(port => res.send(`Code-server 已部署在端口: ${port}，密码已设置。`))
       .catch(error => res.status(500).send(`部署时出错: ${error.message}`));
});



const PORT = 3000;
app.listen(PORT, () => console.log(`服务器运行在 http://localhost:${PORT}`));