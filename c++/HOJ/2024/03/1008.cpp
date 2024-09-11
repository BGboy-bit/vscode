#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
typedef array<ll, 2> PII; // vector<PII> a(n + 1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int maxn = 2e5 + 10;
bool multi = 1;

struct node {
    ll dis, u;
    bool operator>(const node& a) const { return dis > a.dis; }
};

vector<pair<ll, ll>> e[maxn];
ll dis[maxn], vis[maxn];
priority_queue <pair<int, int> >q;


ll lowbit(ll x) {return x & (-x);}

void Solve() {
    ll n, m, k; cin >> n >> m >> k;
    dis[0] = 0;
    for(ll i = 1; i <= n; i ++ ) {
        dis[i] = inf;
        vis[i] = 0;
    }
    for(ll i = 1; i <= m; i ++ ) {
        ll u, v, t; cin >> u >> v >> t;
        e[u].push_back({v, t});
        e[v].push_back({u, t});
    }
    for(ll i = 2; i <= n; i ++ ) {
        e[1].push_back({i, k * (1 | i)});
    }

    dis[1] = 0;
    q.push({0, 1});
    while (!q.empty()) {
        ll u = q.top().second;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto ed : e[u]) {
            ll v = ed.first;
            ll w = ed.second;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push({dis[v], v});
            }
        }
    }

    vector<ll> mindis(n + 1);
    for(ll i = 1; i <= n; i ++ ) {
        mindis[i] = dis[i]; vis[i] = 0;
    }
    for(ll i = 2; i <= n; i ++ ) {
        if(i != lowbit(i)) {
            for(ll j = 0; (1 << j) <= n; j ++ ) {
                if(i & (1 << j)) mindis[i] = min(mindis[i], mindis[(1 << j) ^ i]);
            }
        }
        if(mindis[i] + k * i < dis[i]) dis[i] = mindis[i] + k * i;
    }
    for(ll i = 1; i <= n; i ++ ) q.push({-dis[i], i});
    while (!q.empty()){
        ll u = q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for (auto ed : e[u]) {
            ll v = ed.first;
            ll w = ed.second;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push({dis[v], v});
            }
        }            
    }

    for(ll i = 2; i <= n; i ++ ) cout << dis[i] << " \n"[i == n];
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}