#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;

constexpr int N =1E5+10;

int cnt[N][31];
int ans[N][31];

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<array<int,3>> a;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        for(int j=0;j<=30;j++){
            int t=(w>>j&1);
            if(t){
                cnt[u][j]++;
                cnt[v][j]++;
            }
        }
        a.push_back({u,v,w});
    }

    for(int j=0;j<=30;j++){
        vector<int> p(n+1);
        iota(p.begin(),p.end(),0);
        sort(p.begin()+1,p.end(),[&](int x,int y){
            return cnt[x][j]>cnt[y][j];
        });
        for(int i=1;i<=n;i++){
            
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
}