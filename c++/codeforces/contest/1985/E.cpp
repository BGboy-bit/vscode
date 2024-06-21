#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll x, y, z, k; cin >> x >> y >> z >> k;
    ll ans = 0;
    for(ll i = 1; i <= x; i ++ ) {
        for(ll j = 1; j <= y; j ++ ) {
            if(k % (i * j)) continue;
            ll c = k / (i * j);
            if(c > z) continue;
            ans = max(ans, (x - i + 1) * (y - j + 1) * (z - c + 1)); 
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T; cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}