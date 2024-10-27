#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
using PII = pair<int,int>;

constexpr ll INF = 2E18 + 10;
constexpr int N = 1E5 + 10;

int n;
int b[N];
vector<int> g[N];
int rt;
int fz=0,fm=1;

void dfs1(int u,int fa,ll sum,int nu){
    if(nu>1 && sum*fm>fz*nu){
        // ans=sum/(nu*1.0);
        fz=sum;
        fm=nu;
        rt=u;
    }
    for(auto v : g[u]){
        if(v==fa) continue;
        dfs1(v,u,sum+b[v],nu+1);
    }
}
void dfs2(int u,int fa,ll sum,int nu){
    if(nu>1 && sum*fm>fz*nu){
        // ans=sum/(nu*1.0);
        fz=sum;
        fm=nu;
    }
    for(auto v : g[u]){
        if(v==fa) continue;
        dfs2(v,u,sum+b[v],nu+1);
    }
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs1(1,-1,b[1],1);
    dfs2(rt,-1,b[rt],1);
    for(int i=1;i<=n;i++){
        b[i]=-b[i];
    }
    dfs1(1,-1,b[1],1);
    dfs2(rt,-1,b[rt],1);

    double fs = fz*1.0/fm; // 对称轴
    double ans=fs/4.0*fs;
    cout<<ans<<"\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cout<<fixed<<setprecision(10);
    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
}