#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void  Solve() {
    ll n; cin >> n;
    vector<ll> a(n + 1);
    a[0] = INT_MAX;
    ll ans = INT_MAX;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
        ans = min(ans, max(a[i], a[i - 1]) - 1);
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

