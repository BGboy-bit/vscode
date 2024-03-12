//最大流EK（邻接矩阵）
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 1210;
const int inf = 0x3f3f3f3f;
ll graph[MAX][MAX];
ll n, m, st, ed;
ll ans;
ll pre[MAX];
bool vis[MAX];    
ll l[MAX];//记录bfs路径

bool bfs() {
    memset(pre, -1, sizeof(pre));
    memset(vis, 0, sizeof(vis));
    ll hh = 0, tt = 0;
    pre[st] = st;
    vis[st] = 1;
    l[ ++ tt] = st;

    while(hh < tt) {
        ll pos = l[ ++ hh];
        for(ll i = 1; i <= n; i ++ ) {
            if(!vis[i] && graph[pos][i] > 0) {
                vis[i] = 1;
                pre[i] = pos;
                if(i == ed) return true;
                l[ ++ tt] = i;
            }
        }
    }
    return false;
}

void EK() {    
    while(bfs()) {
        ll w = inf;
        for(ll i = ed; i != st; i = pre[i]) w = min(w, graph[pre[i]][i]);
        for(ll i = ed; i != st; i = pre[i]) {
            graph[pre[i]][i] -= w;
            graph[i][pre[i]] += w;
        }
        ans += w;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> st >> ed;
    ll x, y, z;
    for(ll i = 1; i <= m; i ++ ) {
        cin >> x >> y >> z;
        if(graph[x][y] == 0) graph[x][y] = z;
        else graph[x][y] += z;
    }
    EK();
    cout << ans << "\n";
    return 0;
}