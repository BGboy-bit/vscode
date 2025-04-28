#include<bits/stdc++.h>
#define int long long
using namespace std;

using ll = long long;
using pii = pair<int,int>;

constexpr ll N =2E6 + 10, inf = 2E18 + 10;

void solve()
{
    int n,q;
    cin>>n>>q;
    vector<int> x(n+1);
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    vector<map<pii,int>> mp;
    for(int i=1;i<n;i++){
        for(int j=30;j>=0;j--){
            int t1=(x[i]>>j&1),t2=(x[i+1]>>j&1);
            mp[j][{t1,t2}]=i;
        }
    }
    map<pii,vector<pii>> p;
    p[{0,0}]={{1,0},{0,0}};
    p[{0,1}]={{1,0},{1,1}};
    p[{1,0}]={{0,1},{1,1}};
    p[{1,1}]={{0,1},{0,0}};
    while(q--){
        int a,b;
        cin>>a>>b;
        for(int j=30;j>=0;j--){
            int t1=(a>>j&1),t2=(b>>j&1);
            for(auto[x,y] : p[{t1,t2}]){
                if(mp[j].count({x,y})){

                }
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }

    return 0;
}