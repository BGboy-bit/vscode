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
    ll n; cin >> n;
    string s; cin >> s; s = "!" + s;
    vector<ll> a(27);
    ll ans = 0;
    for(ll i = n; i >= 1; i -- ) {
        if(a[s[i] - 'a'] == 0) {
            a[s[i] - 'a'] = 1;
        } else if(a[s[i] - 'a'] == 1) {
            ans = max(ans, i);
        }
    }
    for(ll i = 0; i <= 26; i ++ ) a[i] = 0;
    for(ll i = 1; i <= n; i ++ ) {
        if(a[s[i] - 'a'] == 0) {
            a[s[i] - 'a'] = 1;
        } else if(a[s[i] - 'a'] == 1) {
            ans = max(ans, n - i);
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