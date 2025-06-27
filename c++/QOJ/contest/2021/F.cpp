#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, k; 

ll AC(ll c, vector<ll> &col, vector<vector<ll>> &g) {
    queue<ll> q;
    vector<ll> vis(n + 1);
    ll ans = k + 1;
    for(ll i = 0; (1 << i) <= n; i ++ ) {
        while(!q.empty()) q.pop();
        for(ll j = 1; j <= n; j ++ ) {
            vis[j] = 0;
            ll x = j & (1 << i);
            if(col[j] == c && (x) > 0) {
                vis[j] = 1;
                q.push(j);
            }
        }
        while(!q.empty()) {
            ll cur = q.front(); q.pop();
            for(auto v : g[cur]) {
                if(!vis[v]) {
                    if(col[v] == c) {
                        ans = min(ans, vis[cur] + 1);
                        if(ans <= k) {
                            return ans;
                        }
                        break;
                    } else {
                        vis[v] = vis[cur] + 1;
                        q.push(v);
                    }
                }
            }
        }
        while(!q.empty()) q.pop();
        for(ll j = 1; j <= n; j ++ ) {
            vis[j] = 0;
            ll x = j & (1 << i);
            if(col[j] == c && (x) == 0) {
                vis[j] = 1;
                q.push(j);
            }
        }
        while(!q.empty()) {
            ll cur = q.front(); q.pop();
            for(auto v : g[cur]) {
                if(!vis[v]) {
                    if(col[v] == c) {
                        ans = min(ans, vis[cur] + 1);
                        if(ans <= k) {
                            return ans;
                        }
                        break;
                    } else {
                        vis[v] = vis[cur] + 1;
                        q.push(v);
                    }
                }
            }
        }
    }
    return ans;
}

void Solve() {
    cin >> n >> m >> k;
    vector<ll> col(n + 1);
    for(ll i = 1; i <= n; i ++ ) {
        cin >> col[i];
    }
    vector<vector<ll>> g(n + 1);
    for(ll i = 1; i <= m; i ++ ) {
        ll u, v; cin >> u >> v;
        g[u].push_back(v);
    }
    for(ll i = 1; i <= 50; i ++ ) {
        ll ans = AC(i, col, g);
        // cout << ans << "\n";
        if(ans <= k) {
            cout << "NO\n"; return ;
        }
    }
    cout << "YES\n"; 
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
/*
3
3 2 2
1 2 1
1 2
2 3
3 3 2
1 2 1
1 2
2 3
1 3
3 3 50
1 1 2
1 2
2 3
1 3
*/