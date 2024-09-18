#include<bits/stdc++.h>
#define int long long
using ll = long long;
using namespace std;
constexpr ll INF = 2E18+10;

void solve()
{
    int n;cin>>n;
    // vector<int> mp(26,0);
    vector<set<string>> mp(26);
    int mx=0;
    for(int i=1;i<=n;i++){
        string a,c;
        char b;
        cin>>a>>b>>c;
        if(c=="accepted"){
            mp[b-'A'].emplace(a);
            mx=max(mx,(ll)mp[b-'A'].size());
        }
    }
    for(int i=0;i<26;i++){
        if(mp[i].size()==mx){
            cout<<char('A'+i)<<"\n";
            return ;
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