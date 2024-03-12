#include <bits/stdc++.h>
using namespace std;

constexpr int N = 250 * 2 + 2 + 7;
constexpr int M = 250 * 250 + 250 * 2 + 7;
constexpr int INF = INT_MAX;

int n, m, S, T, nod;
char s[N][N];
int sc[N], cl[N];

struct Edge {
    int to, ne, f;
} g[M << 1];
int head[N], tot = 1;

//add an edge to the graph
void addedge(int x, int y, int z) {
    g[++tot].to = y;
    g[tot].f = z;
    g[tot].ne = head[x];
    head[x] = tot;
}

//add a directed edge and its reverse edge with the same capacity to the graph
void adde(int x, int y, int z) {
    addedge(x, y, z);
    addedge(y, x, 0);
}

int dis[N], gap[N], cur[N], q[N];
//bfs from the sink node to compute the dis and gap
void bfs() {
    int hd = 0, tl = 0;
    q[++tl] = T;
    ++gap[dis[T] = 1];
    while (hd < tl) {
        int x = q[++hd];
        for (int i = head[x], y = g[i].to; i; i = g[i].ne, y = g[i].to)
            if (!dis[y] && g[i ^ 1].f) {
                dis[y] = dis[x] + 1;
                ++gap[dis[y]];
                q[++tl] = y;
            }
    }
}

//dfs returns the maximum flow that can be pushed from node x to the sink node
int dfs(int x, int a) {
    if (x == T || !a) return a;
    int flow = 0, f;
    for (int& i = cur[x]; i; i = g[i].ne)
        if (dis[x] == dis[g[i].to] + 1 && (f = dfs(g[i].to, min(a, g[i].f)))) {
            g[i].f -= f;
            g[i ^ 1].f += f;
            a -= f;
            flow += f;
            if (!a) return flow;
        }
    --gap[dis[x]];
    if (!gap[dis[x]]) dis[S] = nod + 1;
    ++gap[++dis[x]];
    return flow;
}
/*It initializes ans to 0 and performs repeated iterations of the BFS and DFS
steps until the distance label of the source node exceeds nod*/
int maxFlow() {
    static int ans = 0;
    bfs();
    while (dis[S] <= nod) {
        memcpy(cur + 1, head + 1, sizeof(*head) * nod);
        ans += dfs(S, INF);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int c, d, mxk = 0, sum = 0;
    cin >> n >> m >> c >> d;
    for (int i = 1; i <= n; ++i) {
        cin >> (s[i] + 1);
        for (int j = 1; j <= m; ++j)
            s[i][j] = s[i][j] == '.' ? 1 : 0,
            sc[i] += s[i][j],
            cl[j] += s[i][j],
            mxk = max(mxk, cl[j]);
        mxk = max(mxk, sc[i]);
        sum += sc[i];
    }

    S = n + m + 1;
    T = nod = S + 1;
    for (int i = 1; i <= n; ++i) adde(S, i, 0); // Connect source to rows
    for (int i = 1; i <= m; ++i) adde(i + n, T, 0); // Connect columns to sink
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (s[i][j])
                adde(i, j + n, 1); // Connect filled cells in the grid

    long long ans = LLONG_MAX;
    for (int k = 0; k <= mxk; ++k) {
        if (k) {
            memset(gap + 1, 0, sizeof(*gap) * nod);
            memset(dis + 1, 0, sizeof(*dis) * nod);
            for (int i = 1; i <= n; ++i) ++g[i * 2].f; // Increase capacity of row edges
            for (int i = 1; i <= m; ++i) ++g[(i + n) * 2].f; // Increase capacity of column edges
        }
        ans = min(ans, (long long)c * k + (long long)d * (sum - maxFlow())); // Compute cost
    }
    cout << ans << '\n'; // Output minimum cost

    return 0;
}


