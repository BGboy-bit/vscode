#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll inf = 2e18;
ll n;

ll DP(vector<vector<ll>> &h, vector<ll> &a) {
    vector<vector<ll>> dp(n + 1, vector<ll> (2, inf));
    dp[1][0] = 0, dp[1][1] = a[1];
    for(ll i = 2; i <= n; i ++ ) {
        for(ll x = 0; x < 2; x ++ ) {
            for(ll y = 0; y < 2; y ++ ) {
                bool ff = false;
                for(ll j = 1; j <= n; j ++ ) {
                    if(h[i][j] + x == h[i - 1][j] + y) {
                        ff = true; break;
                    }
                }
                if(!ff) {
                    if(x == 0) {
                        dp[i][x] = min(dp[i][x], dp[i - 1][y]);
                    } else {
                        dp[i][x] = min(dp[i][x], dp[i - 1][y] + a[i]);
                    }
                }
            }
        }
    }
    return min(dp[n][0], dp[n][1]);
}

void Solve() {
    cin >> n;
    vector<vector<ll>> h(n + 1, vector<ll> (n + 1));
    for(ll i = 1; i <= n; i ++ ) {
        for(ll j = 1; j <= n; j ++ ) {
            cin >> h[i][j];
        }
    }
    vector<ll> a(n + 1), b(n + 1);
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
    }
    for(ll i = 1; i <= n; i ++ ) {
        cin >> b[i];
    }
    ll ans = DP(h, a);
    for(ll i = 1; i <= n; i ++ ) {
        for(ll j = 1; j <= i; j ++ ) {
            swap(h[i][j], h[j][i]);
        }
    }
    ans += DP(h, b);
    if(ans >= inf) ans = -1;
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