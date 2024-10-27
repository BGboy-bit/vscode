#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;

constexpr int N =2E6+10;

const string ss = "edgnb";

void solve()
{
    string s; cin >> s;
    ll sum = 0, res = 0;
    for(ll i = 0; i < s.size(); i ++ ) {
        if(s[i] == ss[res]) {
            res ++ ;
            if(res == 5) {
                sum ++ ; res = 0;
            }
        } else {
            res = 0;
            if(s[i] == ss[res]) {
                res ++ ;
            }
        }
    }
    cout << sum << "\n";
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