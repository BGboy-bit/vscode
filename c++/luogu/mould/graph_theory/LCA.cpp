// P3379 【模板】最近公共祖先（LCA）
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 500500;
vector<ll> g[N];
ll fa[N];  // 父节点
ll dep[N]; // 深度
ll top[N]; // 重链头节点
ll sz[N];  // 子树大小
ll son[N]; // 重子节点

void dfs1(ll u) { // 维护子树大小、节点深度、父节点、重子节点
    sz[u] = 1;
    dep[u] = dep[fa[u]] + 1;
    for(auto v : g[u]) {
        if(v == fa[u]) continue;
        fa[v] = u;
        dfs1(v);
        sz[u] += sz[v];
        if(sz[v] > sz[son[u]]) son[u] = v;
    }
}

void dfs2(ll u, ll h) { //维护重链头节点
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
    ll n, m, s; cin >> n >> m >> s;
    for(ll i = 1; i < n; i ++ ) {
        ll u, v; cin >> u >> v;
        g[u].push_back(v); 
        g[v].push_back(u);
    }
    dfs1(s); dfs2(s, s);
    for(ll i = 1; i <= m; i ++ ) {
        ll u, v; cin >> u >> v;
        cout << LCA(u, v) << "\n"; 
    }
    return 0;
}
