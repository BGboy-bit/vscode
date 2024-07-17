// P3379 【模板】最近公共祖先（LCA）
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 6;
vector<ll> g[N];
ll dfn[N];       // dfs时间戳
ll st[N][3];    // st数组，前一个参数为dfn[u], 后一个参数为fa[u] 
ll dn;           // 时间戳

void dfs(ll u, ll fa) {  // 维护时间戳
    st[dfn[u] = ++ dn][0] = fa;
    for(auto v : g[u]) {
        if(v != fa) dfs(v, u);
    }
}

ll get(ll x, ll y) {   // 求最小的时间戳的节点
    return dfn[x] < dfn[y] ? x : y;
}

void ST(ll n) {         // 构造st数组
    for(ll j = 1; j <= __lg(n); j ++ ) {
        for(ll i = 1; i <= n - (1 << j) + 1; i ++ ) {
            st[i][j] = get(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

ll LCA(ll u, ll v) {
    if(u == v) return u;
    if((u = dfn[u]) > (v = dfn[v])) swap(u, v);
    ll k = __lg(v - u ++ );
    ll d = v - (1 << k) + 1;
    return get(st[u][k], st[d][k]);
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
    dfs(s, 0); ST(n);
    for(ll i = 1; i <= m; i ++ ) {
        ll u, v; cin >> u >> v;
        cout << LCA(u, v) << "\n";
    }
    return 0;
}