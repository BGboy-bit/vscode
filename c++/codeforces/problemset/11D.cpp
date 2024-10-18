// https://codeforces.com/problemset/problem/11/D
// D. A Simple Task

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[1 << 19][20];
    
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll n, m; cin >> n >> m;
    vector<vector<ll>> a(n + 1);
    for(ll i = 1; i <= m; i ++ ) {
        ll x, y; cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for(ll i = 1; i <= n; i ++ ) {
        dp[1 << (i - 1)][i] = 1;
    }
    ll ans = 0;
    for(ll i = 1; i < (1 << n); i ++ ) {
        for(ll u = 1; u <= n; u ++ ) {
            if(!dp[i][u]) continue;
            for(auto v : a[u]) {
                if((i & -i) > (1 << v)) continue;
                if(i & (1 << v)) {
                    if((i & -i) == (1 << v)) ans += dp[i][u];
                } else {
                    dp[i | (1 << v)][v] += dp[i][u];
                }
            }
        }
    }
    cout << (ans - m) / 2 << '\n';
    return 0;
}

// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;

// ll dp[1 << 20][20];
    
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0); cout.tie(0);
//     ll n, m; cin >> n >> m;
//     vector<vector<ll>> a(n + 1);
//     for(ll i = 1; i <= m; i ++ ) {
//         ll x, y; cin >> x >> y;
//         a[x].push_back(y);
//         a[y].push_back(x);
//     }
//     for(ll i = 1; i <= n; i ++ ) {
//         dp[1 << i][i] = 1;
//     }
//     ll ans = 0;
//     for(ll i = 1; i < (1 << (n + 1)); i ++ ) {
//         for(ll u = 1; u <= n; u ++ ) {
//             if(!dp[i][u]) continue;
//             for(auto v : a[u]) {
//                 if((i & -i) > (1 << v)) continue;
//                 if(i & (1 << v)) {
//                     if((i & -i) == (1 << v)) ans += dp[i][u];
//                 } else {
//                     dp[i | (1 << v)][v] += dp[i][u];
//                 }
//             }
//         }
//     }
//     cout << (ans - m) / 2 << '\n';
//     return 0;
// }