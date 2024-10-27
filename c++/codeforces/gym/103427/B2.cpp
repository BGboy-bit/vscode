#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
using namespace std;
using ll = long long;

constexpr int N =2E5+10;
int p[N],q[N];
int find(int x)
{
    if(p[x]==x)return x;
    else return p[x]=find(p[x]);

}
vector<PII>g[N];
int u[N],v[N],w[N];
int a[N];
int sum,sum2,f;
void dfs(int un,int cnt)
{
    p[un]=1;
    sum+=cnt;
    a[un]=cnt;
    for(auto [nu,nw]:g[un]){
        if(p[nu]){
            if(a[nu]^a[un]!=nw)f=0;
            continue;
        }
        if(nw==0){
            dfs(nu,cnt);
        }else dfs(nu,1-cnt);
    }
}
void dfs2(int un,int cnt)
{
    sum2+=cnt;
    q[un]=1;
    a[un]=cnt;
    for(auto [nu,nw]:g[un]){
        if(q[nu]){
            if(a[nu]^a[un]!=nw)f=0;
            continue;
        }
        if(nw==0){
            dfs2(nu,cnt);
        }else dfs2(nu,1-cnt);
    }
}
void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];

    }
    int xx=1;
    int ans=0;
    for(int k=0;k<30;k++){
        for(int i=0;i<=n;i++){
            p[i]=0,q[i]=0;
            a[i]=1e18;
            g[i].clear();
        }
        // vector<PII> g[N];
        for(int i=1;i<=m;i++){
            g[u[i]].push_back({v[i],w[i]>>k&1});
            g[v[i]].push_back({u[i],w[i]>>k&1});
        }
        int res=0;
        for(int i=1;i<=n;i++){
            if(p[i]==0){
                sum=0,f=1;
                dfs(i,0);
                if(f==0)sum=1e18;
                sum2=0,f=1;
                dfs2(i,1);
                if(f==0)sum2=1e18;
                if(sum==1e18&&sum2==1e18){
                    cout<<"-1\n";
                    return ;
                }
                res+=min(sum,sum2);
            }
        }
        ans+=xx*res;
        xx*=2;
    }
    cout<<ans<<'\n';

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
}