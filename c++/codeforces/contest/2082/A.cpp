#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n, m; cin >> n >> m;
    vector<ll> row(n + 1), col(m + 1);
    vector<pair<ll, ll>> ele; 
    for(ll i = 1; i <= n; i ++ ) {
        string s; cin >> s; s = "!" + s;
        for(ll j = 1; j <= m; j ++ ) {
            ll x = s[j] - '0';
            if(x == 1) {
                row[i] ++ ;
                col[j] ++ ;
                ele.push_back({i, j});
            }
        }
    }
    ll ans = 0;
    for(auto [x, y] : ele) {
        if(row[x] % 2 != 0 && col[y] % 2 != 0) {
            ans ++ ;
            row[x] -- ; col[y] -- ;
        }
    }
    for(ll i = 1; i <= n; i ++ ) {
        for(ll j = 1; j <= m; j ++ ) {
            if(row[i] % 2 != 0 && col[j] % 2 != 0) {
                ans ++ ;
                row[i] ++ ; col[j] ++ ;
            }
        }
    }
    for(ll i = 1; i <= n; i ++ ) {
        for(ll j = 1; j <= m; j ++ ) {
            if(row[i] % 2 != 0) {
                ans ++ ;
                row[i] ++ ;
            }
            if(col[j] % 2 != 0) {
                ans ++ ;
                col[j] ++ ;
            }
        }
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