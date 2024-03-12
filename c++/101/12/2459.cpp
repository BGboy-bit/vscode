#include <bits/stdc++.h>
using namespace std;

struct Edge {
    char c1, c2;
    int z;
};

int n, m;
char c[100];
vector<vector<pair<int, int>>> graph;
vector<bool> visited;

void init() {
    graph.resize(n);
    visited.resize(n, false);
}

void addEdge(int u, int v, int z) {
    graph[u].push_back(make_pair(v, z));
    graph[v].push_back(make_pair(u, z));
}

void Prim() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, 0));
    int cnt = 0, ans = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int z = pq.top().first;
        pq.pop();

        if (visited[u])
            continue;

        visited[u] = true;
        ans += z;
        if (cnt < n - 1) {
            if (u != 0)
                printf("%c,%c:%d\n", c[u], c[z], u);

            cnt++;
        }

        for (auto edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (!visited[v])
                pq.push(make_pair(weight, v));
        }
    }

    if (cnt < n - 1) {
        printf("ERROR");
    } else {
        printf("\n%d", ans);
    }
}

int main() {
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        scanf("%c ", &c[i]);
    }
    scanf("%d", &m);
    init();
    for (int i = 0; i < m; i++) {
        char c1, c2;
        int z;
        scanf(" %c,%c:%d", &c1, &c2, &z);
        int u = find(c, c + n, c1) - c;
        int v = find(c, c + n, c2) - c;
        addEdge(u, v, z);
    }
    Prim();
    return 0;
}