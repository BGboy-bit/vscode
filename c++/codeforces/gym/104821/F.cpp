#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long

const int N = 2e6 + 10;

struct DSU{
    vector<int> f,siz;
    DSU(int n) : f(n),siz(n,1){iota(f.begin(),f.end(),0);}
    int find(int x){
        while(x!=f[x]) x=f[x]=f[f[x]];
        return x;
    }
    bool same(int x,int y) {return find(x)==find(y);}
    bool merge(int x,int y){
        x=find(x);y=find(y);
        if(x==y) return false;
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
    vector<vector<int>> p(n+1);
    for(int i=1;i<=n;i++){
        int nu;cin>>nu;
        for(int j=1;j<=nu;j++){
            int x;cin>>x;
            p[i].push_back(x);
        }
    }
    vector<int> vis(m+1);
    for(auto it : p[1]){
        vis[it]++;
    }
    int po=-1;
    for(int i=2;i<=n;i++){
        bool sa=0;
        for(int it : p[i]){
            vis[it]++;
            if(vis[it]>1) sa=1;
        }
        if(!sa){
            po=i;
        }
        for(int it : p[i-1]){
            vis[it]--;
        }
    }
    if(po==-1){
        cout<<"No\n";
        return ;
    }
    cout<<"Yes\n";
    for(int i=1;i<=n;i++){
        if(i==po-1) cout<< po <<" ";
        else if(i== po) cout<<po-1<<" ";
        else cout<<i<<" ";
    }
    cout<<"\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int testcase=1;
    cin>>testcase;
    while(testcase--){
        solve();
    }
}
