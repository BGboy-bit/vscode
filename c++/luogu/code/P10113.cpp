// P10113 [GESP202312 八级] 大量的工作沟通
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10;
vector<ll> g[N];
ll fa[N], dep[N], top[N], sz[N], son[N];

void dfs1(ll u) {
    sz[u] = 1; 
    dep[u] = dep[fa[u]] + 1;
    for(auto v : g[u]) {
        if(v == fa[u]) continue;
        fa[v] = u;
        dfs1(v);
        sz[u] += sz[v];
        if(sz[v] > sz[son[v]]) son[u] = v;       
    }
}

void dfs2(ll u, ll h) {
    top[u] = h;
    if(son[u]) dfs2(son[u], h);
    for(auto v : g[u]) {
        if(v == fa[u] || v == son[u]) continue;
        dfs2(v, v);
    }
}

ll LCA(ll u, ll v) {
    while(top[u] != top[v]) {
        if(dep[top[u]] > dep[top[v]])
            u = fa[top[u]];
        else 
            v = fa[top[v]];
    }
    return dep[u] < dep[v] ? u : v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    for(ll i = 1; i < n; i ++ ) {
        ll f; cin >> f;
        g[i].push_back(f);
        g[f].push_back(i);
    }
    dfs1(0), dfs2(0, 0);
    ll q; cin >> q;
    for(ll i = 1; i <= q; i ++ ) {
        ll ans;
        ll m; cin >> m;
        ll l, r; cin >> l;
        for(ll j = 2; j <= m; j ++ ) {
            cin >> r;
            ans = LCA(l, r);
            l = ans;
        }
        ll maxx = 0;
        while(ans != 0) {
            maxx = max(maxx, ans);
            ans = fa[ans];
        }
        cout << maxx << "\n";
    }
    return 0;
}