#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int inf = 2e9 + 10;

ll n, s1, s2; 

void dij(vector<vector<ll>> &vis, vector<vector<ll>> &d, vector<vector<ll>> &g1, vector<vector<ll>> &g2) {
    priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> pq;
    pq.push({0, {s1, s2}});
    while(!pq.empty()) {
        auto [x, y] = pq.top(); pq.pop();
        ll u1 = y.first, u2 = y.second;
        if(vis[u1][u2]) continue;
        // cout << u1 << " " << u2 << "\n";
        vis[u1][u2] = 1;
        for(auto v1 : g1[u1]) {
            for(auto v2 : g2[u2]) {
                if(d[v1][v2] > d[u1][u2] + abs(v1 - v2)) {
                    d[v1][v2] = d[u1][u2] + abs(v1 - v2);
                    pq.push({d[v1][v2], {v1, v2}});
                }
            }
        }
    }
}

void Solve() {
    cin >> n >> s1 >> s2;
    vector<vector<ll>> g1(n + 1), g2(n + 1);
    vector<vector<ll>> mp1(n + 1, vector<ll> (n + 1)), mp2(n + 1, vector<ll> (n + 1));
    vector<vector<ll>> d(n + 1, vector<ll> (n + 1, inf)), vis(n + 1, vector<ll> (n + 1));
    ll m1; cin >> m1;
    for(ll i = 1; i <= m1; i ++ ) {
        ll a, b; cin >> a >> b;
        g1[a].push_back(b); g1[b].push_back(a);
        mp1[a][b] = 1; mp1[b][a] = 1;
    }
    ll m2; cin >> m2;
    for(ll i = 1; i <= m2; i ++ ) {
        ll a, b; cin >> a >> b;
        g2[a].push_back(b); g2[b].push_back(a);
        mp2[a][b] = 1; mp2[b][a] = 1;
    }
    d[s1][s2] = 0;
    dij(vis, d, g1, g2);
    ll ans = 2e9 + 10;
    for(ll i = 1; i <= n; i ++ ) {
        for(ll j = 1; j <= n; j ++ ) {
            if(mp1[i][j] && mp2[i][j]) {
                // cout << i << " " << d[i][i] << "\n";
                ans = min(ans, d[i][i]);
            }
        }
    }
    if(ans > 2e9) {
        cout << "-1\n";
    } else {
        cout << ans << "\n";
    }
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