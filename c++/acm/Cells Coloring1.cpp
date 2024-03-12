#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define LL long long
using namespace std;
const int inf=1<<29;
const int N=207;
const int M=5e3+7;
int n,m,s,t,cnt=1;//从编号2开始建边 
LL maxf;//最大流 
int head[N], vis[N], pre[N];
LL incf[N];
LL v[N][N]; 
struct edge {
    int v, nxt;
    LL w;
}e[M << 1];//因为要建反向边，所以开二倍空间 
void add_edge(int u,int v,LL w){//存边 
    cnt++;
    e[cnt].v=v;
    e[cnt].w=w;
    e[cnt].nxt=head[u];
    head[u]=cnt;
}
bool bfs(){
    memset(vis,0,sizeof(vis));
    queue<int>q;
    q.push(s);
    vis[s]=1; 
    incf[s]=inf;
    while(q.size()){
        int now=q.front();q.pop();
        for(int i=head[now];i;i=e[i].nxt){
            if(e[i].w==0||vis[e[i].v])continue;
            int to=e[i].v;
            incf[to]=min(incf[now],e[i].w);//记录路径最小边的流量 
            pre[to]=i;//记录路径边的编号 
            q.push(to);
            vis[to]=1;
            if(to==t)return 1;
        }
    }
    return 0;
}
void up(){
    int x=t;
    while(x!=s){
        int i=pre[x];
         e[i].w-=incf[t];
         e[i^1].w+=incf[t];
         x=e[i^1].v;//反向边加上正向边减少的流量 
    }
    maxf+=incf[t];
} 
inline int read()
{
    int x = 0 , f = 1;  char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-')  f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') {x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();}
    return x * f;
}
int main(){
    n = read(); m = read(); s = read(); t = read();
    for(int i=1;i<=m;i++){
        int x,y,z;
        x = read(); y = read(); z = read();
        v[x][y] += z;
    }
    for(int i = 1;i <= n;i ++) for(int j = 1;j <= n;j ++) if(v[i][j]) add_edge(i,j,v[i][j]),add_edge(j,i,0);
    while(bfs())up();
    cout<<maxf<<endl;
}