#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n; cin >> n;
    ll ans = 0, cnt = INT_MAX;
    vector<ll> a(n + 1), b(n + 2);
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
    }
    for(ll i = 1; i <= n + 1; i ++ ) {
        cin >> b[i];
    }
    for(ll i = 1; i <= n; i ++ ) {
        ans += abs(b[i] - a[i]);
        if((a[i] <= b[n + 1] && b[n + 1] <= b[i]) || (b[i] <= b[n + 1] && b[n + 1] <= a[i])) {
            cnt = 1;
        } else {
            cnt = min(cnt, min(abs(b[n + 1] - a[i]), abs(b[n + 1] - b[i])) + 1);
        }
    }
    cout << ans + cnt << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T; cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}