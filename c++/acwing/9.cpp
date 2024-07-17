// 9. 分组背包问题

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 110;

ll s[N];
ll v[N][N], w[N][N];
ll dp[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll n, V; cin >> n >> V;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> s[i];
        for(ll j = 1; j <= s[i]; j ++ ) {
            cin >> v[i][j] >> w[i][j];
        }
    }
    for(ll i = 1; i <= n; i ++ ) {
        for(ll j = V; j >= 0; j -- ) {
            for(ll k = 1; k <= s[i]; k ++ ) {
                if(v[i][k] <= j) {
                    dp[j] = max(dp[j], dp[j - v[i][k]] + w[i][k]);
                } 
            }
        }
    }
    cout << dp[V] << "\n";
    return 0;
}