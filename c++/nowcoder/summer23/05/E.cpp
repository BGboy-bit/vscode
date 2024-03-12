#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 1010;
bool multi = 0;//多组输入

vector<ll> edge[MAX];//区间树
struct node {
    ll l, r, w;
};
vector<node> itvl;//intervals
vector<ll> p;
ll n, m;

ll v = 1; 
void build(ll u) {
    while(v <= itvl.size() && itvl[v].r <= itvl[u].r ) {
        edge[u].push_back(v); build(v ++ );
    }
}

void dfs(ll u) {
    ll cnt = 0;
    for(auto v : edge[u]) cnt ^= itvl[v].w;
    cnt ^= itvl[u].w;
    if(cnt) {
        if(edge[u].size() == 0) swap(p[itvl[u].l], p[itvl[u].r]);
        else if(edge[u].size() == 1) {
            if(itvl[edge[u][0]].l == itvl[u].l) swap(p[itvl[u].r - 1], p[itvl[u].r]);
            else swap(p[itvl[u].l], p[itvl[u].l + 1]);
        }
        else swap(p[itvl[edge[u][0]].r], p[itvl[edge[u][1]].l]);
    }
    for(auto v : edge[u]) dfs(v);
}

void Solve() {
    cin >> n >> m;
    itvl.resize(m);
    bool ff = 0, fff = 0;
    for(ll i = 0; i < m; i ++ ) {
        ll l, r, w;
        cin >> l >> r >> w;
        l -- ; r -- ;
        itvl[i].l = l; itvl[i].r = r; itvl[i].w = w;
        if((r - l) * (r - l + 1) / 2 < w) ff = 1;
        if(l == 0 && r == n - 1) fff = 1;
    }
    if(ff) {
        cout << "-1" << "\n"; return ;
    }
    if(!fff) itvl.push_back({0, n - 1, -1});
    sort(itvl.begin(), itvl.end(), [&](node u, node v) {
        if(u.l != v.l) return u.l < v.l;
        if(u.r != v.r) return u.r > v.r;
        return u.w < v.w; 
    });
    build(0);//构造区间树
    p.resize(n);
    iota(p.begin(), p.end(), 1);
    dfs(0);
    for(auto i : p) cout << i << " ";
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}