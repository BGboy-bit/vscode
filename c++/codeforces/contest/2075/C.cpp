#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int M = 2e5 + 10;

void Solve() {
    ll n, m; cin >> n >> m;
    vector<ll> c(m + 1), sum(M);
    for(ll i = 1; i <= m; i ++ ) {
        cin >> c[i];
        sum[c[i]] ++ ;
    }
    sort(c.begin() + 1, c.end());
    for(ll i = 1; i < M; i ++ ) {
        sum[i] += sum[i - 1];
    }
    ll ans = 0, cnt = 0;
    for(ll i = 1; i <= m; i ++ ) {
        ll res = 0;
        if(n > c[i]) { 
            res = sum[n - c[i] - 1];
            if(n > c[i] * 2) res -- ;
        }
        ans += c[i] * (m - 1 - res);
        cnt += m - 1 - res;
    }
    ll x = (m - 1) * (sum[n] - sum[n - 1]);
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