#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
typedef array<ll, 2> PII; // vector<PII> a(n + 1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int maxn = 2e5 + 10;
bool multi = 0;

void Solve() {
    string s; cin >> s;
    reverse(s.begin(), s.end());
    bool ff = 0, ff1 = 0;
    string ans;
    for(ll i = 0; i < s.size(); i ++ ) {
        if(s[i] == '.') {
            if(ff) ans += '.';
            ff1 = 1;
        } else if(!ff1) {
            if(s[i] != '0') {
                ans += s[i];
                ff = 1;
            } else if(s[i] == '0') {
                if(ff) {
                    ans += s[i];
                } 
            }
        } else {
            ans += s[i];
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
}


signed main() {
    // freopen("test.in","r",stdin);  
    // freopen("code.out","w",stdout);    
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}