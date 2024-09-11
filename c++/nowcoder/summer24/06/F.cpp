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



ll find(ll u, vector<ll> &fa) {
    return fa[u] == u ? u : fa[u] = find(fa[u], fa);
}

void Solve() {
    ll n, m; cin >> n >> m;
    vector<vector<ll>> e(n + 1), tree;
    vector<ll> fa(n + 1), siz(n + 1), vis(n + 1);
    for(ll i = 1; i <= n; i ++ ) fa[i] = i;
    for(ll i = 1; i <= m; i ++ ) {
        ll u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
        ll fu = find(u, fa), fv = find(v, fa);
        if(fu != fv) {
            if(siz[fu] > siz[fv]) fa[fv] = fa[fu];
            else fa[fu] = fa[fv];
        } 
    }
    ll cnt = 0;
    for(ll i = 1; i <= n; i ++ ) {
        ll fi = find(i, fa);
        if(vis[fi] == 0) {
            vector<ll> a = {i};
            tree.push_back(a);
            vis[fi] = ++ cnt;
        } else {
            tree[vis[fi]].push_back(i);
        }
    }
    vector<ll> deep;
    
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