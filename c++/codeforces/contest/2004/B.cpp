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
    ll l, r, L, R; cin >> l >> r >> L >> R;
    ll ans = 0;
    vector<ll> a(100 + 1);
    for(ll i = l; i <= r; i ++ ) {
        a[i] ++ ;
    }
    for(ll i = L; i <= R; i ++ ) a[i] ++ ;
    bool ff = 0;
    for(ll i = 1; i <= 100; i ++ ) {
        if(a[i] >= 2) {
            if(!ff) {
                ff = 1;
                if((i > l || i > L) && (i < r || i < R)) {
                    ans += 2;
                } else ans += 1;
            } else {
                if((i > l || i > L) && (i < r || i < R)) {
                    ans += 1;
                }
            }
        }
    }
    if(ans == 0) ans ++ ;
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