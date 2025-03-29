#include<bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
using pii = pair<int,int>;

constexpr ll N = 2E6 + 10, INF = 2E18 + 10;

string ss = "aeiyou";

void solve()
{
    string s; cin >> s;
    cout << s[0];
    for(ll i = 1; i < s.size(); i ++ ) {
        bool ff = 1;
        for(auto c : ss) {
            if(c == s[i]) {
                ff = 0; break;
            }
        }
        if(ff) cout << s[i];
    }
    cout << "\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
}