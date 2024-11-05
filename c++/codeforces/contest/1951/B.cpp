#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n + 1); 
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
    }
    ll x = a[k];
    ll ans = 0, pos = 0;
    swap(a[1], a[k]);
    for(ll i = 2; i <= n; i ++ ) {
        if(x < a[i]) {
            ans = max(ans, i - 2); pos = i; break;
        }
    }
    if(pos == 0) {
        cout << n - 1 << "\n"; return ;
    }
    if(pos < k && a[k] < x) {
        ll y = k;
        for(ll i = pos + 1; i <= k; i ++ ) {
            if(x < a[i]) {
                y = i; break;
            }
        }
        ans = max(ans, y - pos);
    }
    cout << ans << "\n";
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