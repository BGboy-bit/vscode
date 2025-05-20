#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n; cin >> n;
    vector<ll> a(n + 1);
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
    }
    vector<ll> b(n + 1);
    ll mx = 0;
    for(ll i = 1; i <= n; i ++ ) {
        mx = max(mx, a[i]);
        b[i] = mx;
    }
    ll ans = 0;
    for(ll i = n; i >= 1; i -- ) {
        ans += a[i];
        cout << ans - a[i] + b[i] << " \n"[i == 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1; cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}