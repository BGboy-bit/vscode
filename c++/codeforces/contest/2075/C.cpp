#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n, m; cin >> n >> m;
    vector<ll> c(m + 1);
    ll cntt = 0;
    for(ll i = 1; i <= m; i ++ ) {
        cin >> c[i];
        if(c[i] == n) cntt ++ ;
    }
    sort(c.begin() + 1, c.end());
    ll ans = 0, cnt = 0;
    for(ll i = 1; i <= m; i ++ ) {
        ll res = 0;
        if(n > c[i]) { 
            res = upper_bound(c.begin() + 1, c.end(), n - c[i] - 1) - c.begin();
            if(n > c[i] * 2) res -- ;
        }
        ans += c[i] * (m - 1 - res);
        cnt += m - 1 - res;
    }
    ll x = (m - 1) * cntt;
    ans -= cnt / 2 * (n - 1) + x;
    cout << ans * 2 << "\n";
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