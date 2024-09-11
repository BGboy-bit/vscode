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

void dfs(vector<ll> &co, vector<ll> &vis, ll u, ll n) {
    if(u > n) return ;
    if(!vis[u]) {
        co.push_back(u); vis[u] = 1;
    } 
    dfs(co, vis, u * 2, n);
    dfs(co, vis, u * 2 + 1 , n);
}

void Solve() {
    ll n, q; cin >> n >> q;
    vector<ll> fa(n + 1);
    fa[1] = 1;
    for(ll i = 2; i <= n; i ++ ) {
        ll x; cin >> x; 
        fa[i] = x;
    }
    ll cnt = n;
    vector<ll> co;
    co.push_back(1);
    vector<ll> vis(n + 1);
    dfs(co, vis, 1, n);
    vector<ll> pos(n + 1);
    for(ll i = 1; i <= n; i ++ ) {
        pos[co[i]] = i;
    }

    vector<ll> f(n + 1);
    f[1] = 1;
    for(ll i = 2; i <= n; i ++ ) {
        f[i] = pos[fa[co[i]]];
    }
    vector<vector<ll>> s(n + 1);
    for(ll i = 1; i <= n; i ++ ) {
        s[f[i]].push_back(i);
    }

    vector<ll> p(n + 1);
    ll summ = 0;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> p[i];
        if(fa[p[i]] != p[f[i]]) summ ++ ;
    }
    while(q -- ) {
        ll u, v; cin >> u >> v;
        ll sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0, sum6 = 0, sum7 = 0, sum8 = 0;
        if(fa[p[u]] != p[f[u]]) sum5 ++ ;
        if(fa[p[v]] != p[f[v]]) sum6 ++ ;
        for(auto i : s[u]) {
            if(i == v || i == 1) continue;
            if(fa[p[i]] != p[f[i]]) sum1 ++ ;
        }
        for(auto i : s[v]) {
            if(i == u || i == 1) continue;
            if(fa[p[i]] != p[f[i]]) sum2 ++ ;
        }        
        swap(p[u], p[v]);
        if(fa[p[u]] != p[f[u]]) sum7 ++ ;
        if(fa[p[v]] != p[f[v]]) sum8 ++ ;
        for(auto i : s[u]) {
            if(i == v || i == 1) continue;
            if(fa[p[i]] != p[f[i]]) sum3 ++ ;
        }
        for(auto i : s[v]) {
            if(i == u || i == 1) continue;
            if(fa[p[i]] != p[f[i]]) sum4 ++ ;
        }
        summ += sum3 + sum4 - sum1 - sum2 + sum7 + sum8 - sum5 - sum6;
        if(summ == 0) {
            cout << "Yes\n";
        } else cout << "No\n";
    }
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