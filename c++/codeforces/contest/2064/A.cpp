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
bool multi = 1;

void Solve() {
    ll n; cin >> n;
    string s; cin >> s;
    ll ff = -1;
    ll ans = 0;
    for(ll i = n - 1; i >= 0; i -- ) {
        if(s[i] == '1') {
            if(ff == 1) {
                ans += 1;
            } 
            if(ff != 0) {
                ff = 0; ans ++ ;
            }
        }
        if(s[i] == '0') {
            ff = 1;
        }
    }
    cout << ans << "\n";
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