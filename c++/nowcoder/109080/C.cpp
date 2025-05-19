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
    ll n, q; cin >> n >> q;
    vector<ll> a(n + 1);
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
    }
    while(q -- ) {
        ll l, r; cin >> l >> r;
        vector<ll> b(62);
        for(ll i = 0; (1ll << i) <= a[l]; i ++ ) {
            if((1ll << i) & a[l]) {
                b[i] = 1;
            }
        }
        for(ll i = l + 1; i <= r; i ++ ) {
            vector<ll> c(62);
            for(ll j = 0; (1ll << j) <= a[i]; j ++ ) {
                if((1ll << j) & a[i]) {
                    if(b[j] == 1) {
                        c[j + 1] = 1;
                    }
                }
            }
            b = c;
        }
        ll ans = 0;
        for(ll i = 0; i <= 61; i ++ ) {
            if(b[i]) ans += (1ll << i);
        }
        cout << ans << "\n";
    }
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