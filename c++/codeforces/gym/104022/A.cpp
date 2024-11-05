#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;

constexpr ll INF = 2E18 + 10;
constexpr int N = 2E6 + 10;

void solve()
{
    int n;
    cin>>n;
    vector<int>x(n),y(n),z(n);
    vector<set<pair<int,int>>> se(3);
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i]>>z[i];
        se[0].insert({y[i],z[i]});
        se[1].insert({x[i],z[i]});
        se[2].insert({x[i],y[i]});
    }

    vector<pair<int,char>> v(3);
    v[0]={se[0].size(),'X'};
    v[1]={se[1].size(),'Y'};
    v[2]={se[2].size(),'Z'};
    sort(v.begin(),v.end(),[](auto a,auto b){
        if(a.first==b.first) return a.second<b.second;
        return a.first>b.first;
    });
    // for(int i=0;i<3;i++){
    //     cout<<v[i].first<<" "<<v[i].second<<"\n";
    // }
    cout<<v[0].second<<"\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T = 1;
    // cin>>T;
    while(T--){
        solve();
    }
}