#include<bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
using pii = pair<int,int>;

constexpr ll N = 2E6 + 10, INF = 2E18 + 10;

struct DSU{
    vector<int> f,siz;
    DSU(int n):f(n),siz(n,1){iota(f.begin(),f.end(),0);}
    int find(int x){
        while(x!=f[x]) x=f[x]=f[f[x]];
        return x;
    }
    bool same(int x,int y) {return find(x)==find(y);}
    bool merge(int x,int y){
        x=find(x);y=find(y);
        if(x==y) return false;
        if(siz[y]>siz[x]) swap(x,y);
        siz[x]+=siz[y];
        f[y]=x;
        return true;
    }
    int size(int x){return siz[find(x)];}
};

void solve()
{
    int n,m;
    cin>>n>>m;
    DSU dsu(n+1);
    vector<vector<int>> g(n+1);
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        dsu.merge(u,v);
    }
    priority_queue<int,vector<int>,greater<int>> q;
    int ansn=0;
    map<int,int> mp;
    for(int i=1;i<=n;i++){
        if(dsu.find(i)==i) ansn++;
        if(!mp.count(dsu.find(i))){
            mp[dsu.find(i)]=i;
        }else{
            mp[dsu.find(i)]=min(mp[dsu.find(i)],i);
        }
    }
    vector<bool> vis(n+1);
    for(auto [x,y] : mp){
        q.push(y);
        vis[y]=1;
    }
    vector<int> ans;
    
    while(!q.empty()){
        int t=q.top();
        q.pop();
        vis[t]=1;
        ans.push_back(t);
        for(auto v : g[t]){
            if(!vis[v])
                q.push(v);
        }
    }
    cout<<ansn<<"\n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" \n"[i==ans.size()-1];
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
}