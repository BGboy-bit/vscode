#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int inf = 5050;

void Solve() {
    ll n; cin >> n;
    vector<ll> a(n + 1), c(5050);
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i]; c[a[i]] ++ ;
    }
    vector<ll> v;
    v.push_back(0);
    for(ll i = 1; i <= 5000; i ++ ) {
        if(c[i] > 0) {
            v.push_back(c[i]);
        }
    }
    ll cnt = v.size() - 1;
    vector<vector<ll>> dp(cnt + 1, vector<ll>(cnt + 1, inf));     // dp[i][j] Bob 从前 i 种蛋糕中拿走 j 种蛋糕所需的步骤数 
    dp[1][0] = 0;
    for(ll i = 1; i <= cnt; i ++ ) {
        dp[i][0] = 0;
        for(ll j = 1; j < i; j ++ ) {
            dp[i][j] = min(dp[i][j], dp[i - 1][j]);                // Bob 不拿走第 i 个，前 i 个蛋糕中拿走 j 个需要的步骤和前 i - 1 个蛋糕中拿走 j 个一样
            if(dp[i - 1][j - 1] + v[i] <= i - j) {
                dp[i][j] = min(dp[i - 1][j - 1] + v[i], dp[i][j]); // Bob 拿走第 i 个，所需的步骤数即为前 i - 1 个蛋糕拿走 j - 1 个蛋糕的步骤加上拿走第 i 个所需的步骤数
            }
        }
    }
    // for(ll i = 1; i <= cnt; i ++ ) {
    //     for(ll j = 1; j <= cnt; j ++ ) {
    //         cout << dp[i][j] << " \n"[j == cnt];
    //     }
    // }
    ll ans = cnt;
    for(ll i = 1; i < cnt; i ++ ) {
        if(dp[cnt][i] < inf) ans = min(ans, cnt - i);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll t; cin >> t;
    while(t -- ) {
        Solve();
    }
    return 0;
}