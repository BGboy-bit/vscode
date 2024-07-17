// 285. 没有上司的舞会

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 6060;

vector<ll> a(N);
vector<bool> fa(N, false);
vector<vector<ll>> g(N, vector<ll>()), dp(N, vector<ll>(2, 0));
ll idx;

void dfs(ll root) {
    dp[root][1] = a[root];
    for(auto j : g[root]) {
        dfs(j);
        dp[root][0] += max(dp[j][0], dp[j][1]);
        dp[root][1] += dp[j][0];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll n; cin >> n;

    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
    }
    for(ll i = 1; i < n; i ++ ) {
        ll l, k; cin >> l >> k;
        fa[l] = true;
        g[k].push_back(l);
    }

    ll root = 1;
    while(fa[root]) root ++ ;
    dfs(root);

    cout << max(dp[root][1], dp[root][0]) << "\n";
    return 0;
}