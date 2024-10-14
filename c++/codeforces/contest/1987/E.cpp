#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int inf = 1e9;

void Solve() {
    ll n; cin >> n;
    vector<ll> a(n + 1), d(n + 1);
    vector<vector<ll>> g(n + 1);
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
    }
    for(ll i = 2; i <= n; i ++ ) {
        ll x; cin >> x;
        g[x].push_back(i);
        d[i] = d[x] + 1;
    }
    vector<ll> b(n + 1, inf);
    for(ll i = 1; i <= n; i ++ ) {
        if(!g[i].empty()) {
            b[i] = -a[i];
        }
        for(auto j : g[i]) {
            b[i] += a[j];
        }
    }
    ll ans = 0;
    for(ll v = n; v >= 0; v -- ) {
        queue<ll> q;
        q.push(v);
        while(!q.empty()) {
            ll u = q.front(); q.pop();
            for(auto w : g[u]) {
                ll cnt = min(-b[v], b[w]);
                if(cnt > 0) {
                    b[v] += cnt;
                    b[w] -= cnt;
                    ans += cnt * (d[w] - d[v]);
                }
                q.push(w);
            }
        }
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