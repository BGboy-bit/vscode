#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string str = "!narek";

void ac(string s, ll x, ll &pos, ll &sum, ll &m) {
    for(ll i = 1; i <= m; i ++ ) {
        ll p = -1;
        for(ll j = 1; j <= 5; j ++ ) {
            if(str[j] == s[i]) {
                p = j; break;
            }
        } 
        if(p == -1) continue;
        if(p == x) {
            sum ++ ;
            x = x + 1;
            if(x == 6) x = 1;
        } else {
            sum -- ;
        }
    }
    pos = x;
}

void Solve() {
    ll n, m; cin >> n >> m;
    vector<string> s(n + 1);
    for(ll i = 1; i <= n; i ++ ) {
        cin >> s[i];
        s[i] = "!" + s[i];
    }
    vector<vector<ll>> dp(n + 1, vector<ll> (6, -1e6));
    dp[0][1] = 0;
    dp[1][1] = 0;
    for(ll i = 1; i <= n; i ++ ) {
        for(ll j = 1; j <= 5; j ++ ) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            ll pos, sum = 0;
            ac(s[i], j, pos, sum, m);
            dp[i][pos] = max(dp[i][pos], dp[i - 1][j] + sum);
        }
    }
    ll ans = 0;
    for(ll i = 1; i <= 5; i ++ ) {
        ans = max(ans, dp[n][i] - (i - 1) * 2);
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