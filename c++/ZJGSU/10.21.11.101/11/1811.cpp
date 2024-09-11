#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005

int head[MAXN], nxt[MAXN], to[MAXN], idx;
int depth[MAXN], max_depth, max_root;

void add_edge(int u, int v) {
    to[++idx] = v;
    nxt[idx] = head[u];
    head[u] = idx;
}

void dfs(int u, int fa, int d) {
    depth[u] = d;
    if (d > max_depth) {
        max_depth = d;
        max_root = u;
    }
    for (int i = head[u]; i != -1; i = nxt[i]) {
        int v = to[i];
        if (v != fa) {
            dfs(v, u, d + 1);
        }
    }
}

int main() {
    
    int n;
    while(scanf("%d", &n) != EOF) {
        memset(head, -1, sizeof(head));
        for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
        }
        max_depth = -1;
        dfs(1, 0, 0);
        int root = max_root;
        max_depth = -1;
        dfs(root, 0, 0);
        printf("%d %d\n", min(root, max_root), max_depth + 1);
    }
    return 0;
}
