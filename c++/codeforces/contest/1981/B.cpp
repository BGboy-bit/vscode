#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n, m; cin >> n >> m;
    ll l = max(0ll, n - m), r = m + n;
    ll ans = 0;
    for(ll i = 0; i <= 30; i ++ ) {
        ll x = 1ll << i;
        if(l & x || r & x || l >> i < r >> i) ans += x; 
    }
    cout << ans << "\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T; cin >> T;
    while(T -- ) {
        Solve();
    }
}