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
bool multi = 0;

struct Edge {
    ll u, v, w;
};

struct Node {
    ll max1, max2;
    bool f1, f2;
};

bool cmp(Edge x, Edge y) {
    return x.w < y.w;
}

ll find(vector<ll> &fa, ll u) {
    return fa[u] == u ? u : fa[u] = find(fa, fa[u]);
}

void Solve() {
    ll n, m; cin >> n >> m;
    vector<Node> d(n + 1);
    vector<Edge> e(m + 1);
    vector<ll> fa(n + 1);
    iota(fa.begin(), fa.end(), 0);
    for(ll i = 1; i <= m; i ++ ) {
        ll u, v, w; cin >> u >> v >> w;
        e[i].u = u, e[i].v = v; e[i].w = w;
    }
    sort(e.begin() + 1, e.end(), cmp);
    ll ans = inf;
    d[1].f1 = true; d[n].f2 = true;
    for(ll i = 1; i <= m; i ++ ) {
        ll u = e[i].u, v = e[i].v;
        if(u == 1 && v == n || u == n && v == 1) {
            ans = min(ans, e[i].w); continue;
        }
        if(u != 1 && u != n && v != n && v != n) {
            vector<ll> w;
            w.push_back(e[i].w);
            w.push_back(d[u].max1);
            w.push_back(d[u].max2);
            w.push_back(d[v].max1);
            w.push_back(d[v].max2);
            sort(w.begin(), w.end());
            d[u].max1 = d[v].max1 = w[4];
            d[u].max2 = d[v].max2 = w[3];
        } else {
            ll w = e[i].w;
            if(d[u].max1 < w) {
                d[u].max2 = d[u].max1; d[u].max1 = w;
            } else d[u].max2 = max(d[u].max2, w);
            if(d[v].max1 < w) {
                d[v].max2 = d[v].max1; d[v].max1 = w;
            } else d[v].max2 = max(d[v].max2, w);
        }
        // if(d[u].f1 || u == 1) d[v].f1 = true;
        // if(d[v].f1 || v == 1) d[u].f1 = true;
        // if(d[u].f2 || u == n) d[v].f2 = true;
        // if(d[v].f2 || v == n) d[u].f2 = true;
        ll fu = find(fa, u), fv = find(fa, v);
        if(fu == 1) {
            if(fv == n) d[1].f2 = 1;
            fa[fv] = 1;
        } else if(fv == 1) {
            if(fu == n) d[1].f2 = 1;
            fa[fu] = 1;
        } else if(fu == n) {
            fa[fv] = n;
        } else if(fv == n) {
            fa[fu] = n;
        } else {
            fa[fv] = fu;
        }
        if(d[fa[fu]].f1 && d[fa[fu]].f2 && u != 1 && u != n) ans = min(ans, d[u].max1 + d[u].max2);     
        if(d[fa[fv]].f1 && d[fa[fv]].f2 && v != 1 && v != n) ans = min(ans, d[v].max1 + d[v].max2); 
    }
    cout << ans << "\n";
}


signed main() {
    // freopen("test.in","r",stdin);  
    // freopen("code.out","w",stdout);    
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}