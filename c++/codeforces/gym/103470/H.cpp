#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void dfs(ll res, ll fa, vector<vector<ll>> &g, vector<ll> &a, vector<ll> &t, vector<ll> &dp, vector<ll> &f) {
    ll maxx1 = 0, maxx2 = 0;
    f[res] = a[res];
    for(auto i : g[res]) {
        if(i == fa) continue;
        dfs(i, res, g, a, t, dp, f);
        f[res] += dp[i] - a[i];
        ll x = dp[i] - f[i] + a[i];
        if(x > maxx1) {
            maxx2 = maxx1; maxx1 = x;
        } else if(x > maxx2) {
            maxx2 = x;
        }
    }
    dp[res] = f[res];
    for(auto i : g[res]) {
        if(i == fa) continue;
        dp[res] = max(dp[res], f[res] + a[i]);
        if(t[i] == 3) {
            if(dp[i] - f[i] + a[i] == maxx1) dp[res] = max(dp[res], f[res] + a[i] + maxx2);
            else dp[res] = max(dp[res], f[res] + a[i] + maxx1);
        }
    }
}

void solve()
{
    ll n; cin >> n;
    vector<ll> a(n + 1), t(n + 1), dp(n + 1), f(n + 1);
    vector<vector<ll>> g(n + 1);
    for(ll i = 1; i <= n; i ++ ) cin >> a[i];
    for(ll i = 1; i <= n; i ++ ) cin >> t[i];
    for(ll i = 1; i < n; i ++ ) {
        ll u, v; cin >> u >> v;
        g[u].push_back(v);
    }
    dfs(1, 0, g, a, t, dp, f);
    cout << dp[1] << "\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
}