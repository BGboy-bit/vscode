#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int N = 3010;
const int M = N * N / 2;

ll n, m;
ll dfn[N], dfn_maxx;//表示这个点在dfs时是第几个被搜到的
ll low[N];//表示这个点以及其子孙节点连的所有点中dfn最小的值
stack<ll> st;
ll id[N], id_maxx;//标记这个点位于的强连通分量
ll num[N];// 这个强连通分量中的点的数量
ll out[N];//每个强连通分量的出度
ll vis[N];//标记是否在栈中

ll head[N];//每个点连接的第一条边的索引
struct edge {//链式向前星记录的是一个点连接的所有边
    ll to;//目标节点
    ll nxt;//下一条边的索引
}e[M];
ll cnt;//边的总数，从1开始计数
void add_edge(ll u, ll v) {
    cnt ++;
    e[cnt].to = v;
    e[cnt].nxt = head[u];
    head[u] = cnt;
}

void tarjan(ll u) {
    low[u] = dfn[u] = ++ dfn_maxx;
    vis[u] = 1;
    st.push(u);
    for(ll i = head[u]; i; i = e[i].nxt) {
        ll v = e[i].to;
        if(dfn[v] != 0) {
            if(vis[v]) low[u] = min(low[u], dfn[v]);
        }
        else {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
    }
    //找到一个强连通分量的头节点
    if(dfn[u] == low[u]) {
        id[u] = ++ id_maxx;
        num[id_maxx] ++ ;
        vis[u] = 0;
        while(st.top() != u) {
            ll v = st.top(); st.pop();
            vis[v] = 0;
            id[v] = id_maxx;
            num[id_maxx] ++ ;
        }
        st.pop();
    }
}

void Solve() {
    cin >> n;
    for(ll i = 1; i <= n; i ++ ) {
        for(ll j = 1; j <= n; j ++ ) {
            ll f; cin >> f;
            if(f == 1) {
                add_edge(i, j);
            }
        }
    }
    //tarjan找强连通分量
    for(ll i = 1; i <= n; i ++ ) {
        if(!dfn[i]) tarjan(i);
    }
    bool ff = 1;
    for(ll i = 1; i <= id_maxx; i ++ ) {
        if(num[i] < 2) {
            ff = 0; break;
        }
    }
    if(ff) cout << n << "\n";
    else cout << n - 1 << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    // cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}