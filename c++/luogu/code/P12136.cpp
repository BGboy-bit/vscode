#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll maxd = 0;
void dfs(ll cur, ll fa, ll dp, vector<vector<ll>> &d, vector<vector<ll>> &g) {
    for(auto s : g[cur]) {
        if(s == fa) continue;
        maxd = max(maxd, dp);
        d[dp].push_back(s);
        dfs(s, cur, dp + 1, d, g);
    }   
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    vector<ll> w(n + 1); 
    for(ll i = 1; i <= n; i ++ ) {
        cin >> w[i];
    }
    vector<vector<ll>> g(n + 1);
    for(ll i = 1; i < n; i ++ ) {
        ll x, y; cin >> x >> y;
        g[x].push_back(y); g[y].push_back(x);
    }
    vector<vector<ll>> d(n + 1), ans(n + 1);
    d[0].push_back(1);
    dfs(1, 0, 1, d, g);
    for(ll i = maxd; i >= 0; i -- ) {
        for(auto x : d[i]) {
            if(g[x].size() == 1) {
                ans[x].push_back(w[x]); continue;
            }
            vector<ll> b(1001);
            b[0] = 1;
            for(auto y : g[x]) {
                vector<ll> c(1001);
                for(auto z : ans[y]) {
                    for(auto k : ans[x]) {
                        b[k] = 1;
                    }
                    for(ll j = w[x]; j >= z; j -- ) {
                        b[j] |= b[j - z];
                    }
                    for(ll j = 1; j <= 1000; j ++ ) {
                        if(b[j]) {
                            c[j] = 1; b[j] = 0;
                        }
                    }
                }
                for(ll j = 1; j <= 1000; j ++ ) {
                    if(c[j]) {
                        ans[x].push_back(j);
                    }
                }
            }
        }
    }
    cout << *max_element(ans[1].begin(), ans[1].end()) << "\n";
    return 0;
}