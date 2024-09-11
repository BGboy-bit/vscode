#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;
#define int ll
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int M = 3e5 + 10;
const int N = 5e3 + 10;
bool multi = 1;//多组输入

ll n, m;

// Prim
struct Edge {
    int v, w, next;
} E[2 * M];
ll summ;
ll head[M];
void add(int u,int v,int w) {
    E[ ++ summ].v = v;
    E[summ].w = w;
    E[summ].next = head[u];
    head[u] = summ;
}
typedef array<ll, 3> pii;


void Prim(vector<ll> &vis, ll &nw, bool &ff) {
    priority_queue <pii,vector<pii>,greater<pii> > q;
    nw ++ ;
    ll ans = 0;
    ll cnt = 0;
    vector<ll> dis(n + 1, M), vvis(n + 1), res;
    q.push({0, 1, 0});
    while(!q.empty() && cnt < n) {
        int d = q.top()[0], u = q.top()[1], v = q.top()[2];
        q.pop();
        if(vvis[u]) continue;

        cnt ++ ;
        ans += d;
        if(v != 0) res.push_back(v);

        vvis[u] = 1;
        for(ll i = head[u]; i != -1; i = E[i].next) {
            if(vis[(i + 1) / 2] != -1) continue;
            if(E[i].w < dis[E[i].v]) {
                dis[E[i].v] = E[i].w, q.push(pii{dis[E[i].v], E[i].v, i});
            }
        }
    }
    if(cnt < n) ff = 1;
    else {
        for(auto i : res) vis[(i + 1) / 2] = nw;
    }
}


// Kruskal
struct edge {
    ll x, y, z;
}e[M];
bool cmp(edge u, edge v) {
    return u.z < v.z;
}

ll fa[N];
void init() {
    for(ll i = 1; i <= n; i ++ ) fa[i] = i;
}
ll find(ll x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void Kruskal(vector<ll> &vis, ll &nw, bool &ff) {
    nw ++ ;
    vector<ll> b;
    ll cnt = 0;
    if(nw == 1)
    sort(e + 1, e + m + 1, cmp); init();
    for(ll i = 1; i <= m; i ++ ) {
        if(vis[i] != -1) continue;
        ll x = e[i].x, y = e[i].y, z = e[i].z;
        ll fx = find(x), fy = find(y);
        if(fx == fy) continue;
        fa[fx] = fy;
        b.push_back(i);
        cnt ++ ;
    }
    if(cnt < n - 1) ff = 1;
    else {
        for(auto i : b) vis[i] = nw;
    }
}

void Solve() {
    summ = 0;
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for(ll i = 1; i <= m; i ++ ) {
        ll x, y, z;
        cin >> x >> y;
        z = i; 
        e[i].x = x; e[i].y = y; e[i].z = z;
        add(x, y, z);
        add(y, x, z);
    }
    vector<ll> vis(m + 1, -1);
    ll nw = 0;
    bool ff = 0;
    if(n > 500) {
        while(!ff)
            Kruskal(vis, nw, ff);
    } else {
        while(!ff)
            Prim(vis, nw, ff);
    }

    for(ll i = 1; i <= m; i ++ ) {
        cout << vis[i] << " \n"[i == m];
    }
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


// #include<bits/stdc++.h>
// using namespace std;
// typedef __int128 i128;
// typedef long long ll;
// typedef double db;
// #define int ll
// const ll inf = 1e18 + 10;
// const int mod = 998244353;
// const int M = 3e5 + 10;
// const int N = 5e3 + 10;
// bool multi = 1; // Multiple test cases

// ll n, m;

// // Edge structure for graph
// struct Edge {
//     int v, w, next;
// } E[2 * M];
// ll summ;
// ll head[M];

// void add(int u, int v, int w) {
//     E[++summ].v = v;
//     E[summ].w = w;
//     E[summ].next = head[u];
//     head[u] = summ;
// }

// // Naive Prim's algorithm with edge visitation check
// void Prim(vector<ll> &vis, ll &nw, bool &ff) {
//     vector<bool> vvis(n + 1, false); // 顶点访问标记
//     vector<ll> dis(n + 1, inf); // 距离数组初始化为无穷大
//     dis[1] = 0; // 从顶点1开始
//     ll ans = 0;

//     for (ll cnt = 1; cnt <= n; cnt++) {
//         ll u = -1;
//         for (ll i = 1; i <= n; i++) {
//             if (!vvis[i] && (u == -1 || dis[i] < dis[u])) {
//                 u = i; // 选择未访问的最近的顶点
//             }
//         }

//         if (dis[u] == inf) { // 如果最近的顶点距离还是无穷大，说明它不可达
//             ff = true; // 设置失败标志
//             return; // 无法构建最小生成树
//         }

//         vvis[u] = true;
//         ans += dis[u];
//         nw++;

//         for (ll i = head[u]; i != -1; i = E[i].next) {
//             int v = E[i].v;
//             int edgeId = (i + 1) / 2; // 计算边的编号
//             if (!vvis[v] && E[i].w < dis[v] && vis[edgeId] == -1) {
//                 dis[v] = E[i].w; // 更新到达顶点v的最小距离
//             }
//         }
//     }

//     // 标记已使用的边
//     for (ll i = 1; i <= m; i++) {
//         if (vis[i] == -1 && vvis[E[i].v] && vvis[E[(i-1) ^ 1].v]) {
//             vis[i] = nw; // 标记此边为已访问
//         }
//     }
// }



// // Kruskal
// struct edge {
//     ll x, y, z;
// }e[M];
// bool cmp(edge u, edge v) {
//     return u.z < v.z;
// }

// ll fa[N];
// void init() {
//     for(ll i = 1; i <= n; i ++ ) fa[i] = i;
// }
// ll find(ll x) {
//     return fa[x] == x ? x : fa[x] = find(fa[x]);
// }

// void Kruskal(vector<ll> &vis, ll &nw, bool &ff) {
//     nw ++ ;
//     vector<ll> b;
//     ll cnt = 0;
//     sort(e + 1, e + m + 1, cmp); init();
//     for(ll i = 1; i <= m; i ++ ) {
//         if(vis[i] != -1) continue;
//         ll x = e[i].x, y = e[i].y, z = e[i].z;
//         ll fx = find(x), fy = find(y);
//         if(fx == fy) continue;
//         fa[fx] = fy;
//         b.push_back(i);
//         cnt ++ ;
//     }
//     if(cnt < n - 1) ff = 1;
//     else {
//         for(auto i : b) vis[i] = nw;
//     }
// }

// void Solve() {
//     summ = 0;
//     memset(head, -1, sizeof(head));
//     cin >> n >> m;
//     for(ll i = 1; i <= m; i ++ ) {
//         ll x, y, z;
//         cin >> x >> y;
//         z = i; 
//         e[i].x = x; e[i].y = y; e[i].z = z;
//         add(x, y, z);
//         add(y, x, z);
//     }
//     vector<ll> vis(m + 1, -1);
//     ll nw = 0;
//     bool ff = 0;
//     if(n > 5000) {
//         while(!ff)
//             Kruskal(vis, nw, ff);
//     } else {
//         while(!ff)
//             Prim(vis, nw, ff);
//     }

//     for(ll i = 1; i <= m; i ++ ) {
//         cout << vis[i] << " \n"[i == m];
//     }
// }

// signed main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0); cout.tie(0);
//     ll T = 1;   
//     if(multi) cin >> T;
//     while(T--) {
//         Solve();
//     }
//     return 0;
// }
