const express = require('express');
const { exec } = require('child_process');
const net = require('net');
const app = express();

app.use(express.json());

function checkPort(port) {
  return new Promise((resolve, reject) => {
    const server = net.createServer();
    server.listen(port, () => {
      server.once('close', () => {
        resolve(port);
      });
      server.close();
    });
    server.on('error', (err) => {
      reject(err);
    });
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

app.post('/deploy', async (req, res) => {
  const startPort = 10000; // 设定端口搜索起始值
  try {
    const freePort = await findFreePort(startPort);
    const containerName = `coder-${freePort}`;
    const imageName = 'codercom/code-server';
    // 注意这里改为内部8080端口映射到找到的外部freePort
    const command = `docker run -d -p ${freePort}:8080 --name ${containerName} ${imageName}`;
    exec(command, (error, stdout, stderr) => {
      if (error) {
        console.error(`执行错误: ${error}`);
        return res.status(500).send(`部署错误: ${error.message}`);
      }
      res.send(`Docker容器 ${containerName} 启动成功，访问端口: ${freePort}`);
      console.log(`Docker容器 ${containerName} 启动成功，访问端口: ${freePort}`);
    });
  } catch (error) {
    res.status(500).send(`寻找空闲端口错误: ${error.message}`);
  }
});

const PORT = 3000;
app.listen(PORT, () => console.log(`服务器运行在 http://localhost:${PORT}`));


