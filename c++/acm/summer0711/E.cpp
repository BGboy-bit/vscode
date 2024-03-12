// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// typedef double db;

// const int inf = 1e9 + 10;
// const int MAX = 2e5 + 10;
// ll n;
// ll a[MAX];
// ll dp[2][MAX];

// void Solve() {
//     cin >> n;
//     for(ll i = 1; i <= n; i ++ ) {
//         cin >> a[i];
//     }
//     ll ans = 0;
//     dp[1][1] = a[1];
//     for(ll i = 2; i <= n; i ++ ) {
//         dp[0][i] = max(dp[0][i - 1], dp[1][i - 1]);
//         dp[1][i] = dp[0][i - 1] + a[i];
//     }
//     ans = dp[0][n];
//     dp[0][1] = 0;
//     dp[1][1] = -inf;
//     for(ll i = 2; i <= n; i ++ ) {
//         dp[0][i] = max(dp[0][i - 1], dp[1][i - 1]);
//         dp[1][i] = dp[0][i - 1] + a[i];
//     }
//     ans = max(ans, dp[1][n]);
//     ans = max(ans, dp[0][n]);
//     cout << ans << "\n";
// }


// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0); cout.tie(0);
//     ll T = 1;
//     // cin >> T;
//     while(T --) {
//         Solve();
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int inf = 0x3f3f3f3f;
const int MAX = 2e5 + 10;
ll n;
ll a[MAX << 1];
ll dp[MAX << 1];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
    }
    ll ans = 0;
    for(ll i = 1; i <= n; i ++ ) {
        a[i + n] = a[i];
    }
    for(ll i = 1; i <= 2 * n; i ++ ) {
        dp[i] = max(dp[i - 1], (i - 2 < 0 ? 0 : dp[i - 2]) + a[i]);
    }
    cout << dp[2 * n] - dp[n] << "\n";
    return 0;
}