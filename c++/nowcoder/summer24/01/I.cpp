#include <bits/stdc++.h>
 
using i64 = long long;
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
     
    int n, m;
    std::cin >> n >> m;
     
    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }
     
    auto V = [&](int x, int y) {
        return x * (m + 1) + y;
    };
    auto H = [&](int x, int y) {
        return n * (m + 1) + x * m + y;
    };
     
    const int N = n * (m + 1) + (n + 1) * m;
    std::vector<std::array<std::pair<int, int>, 2>> adj(N, {std::make_pair(-1, -1), std::make_pair(-1, -1)});
    std::vector<std::array<int, 2>> tot(N);
     
    auto addEdge = [&](int u, int v, int du, int dv, int w) {
        adj[u][du] = {v * 2 + dv, w};
        adj[v][dv] = {u * 2 + du, w};
    };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int mir = i * m + j;
            if (s[i][j] == '-') {
                addEdge(V(i, j), V(i, j + 1), 1, 0, -1);
                addEdge(H(i, j), H(i, j), 1, 1, mir);
                addEdge(H(i + 1, j), H(i + 1, j), 0, 0, mir);
            } else if (s[i][j] == '|') {
                addEdge(V(i, j), V(i, j), 1, 1, mir);
                addEdge(V(i, j + 1), V(i, j + 1), 0, 0, mir);
                addEdge(H(i, j), H(i + 1, j), 1, 0, -1);
            } else if (s[i][j] == '/') {
                addEdge(V(i, j), H(i, j), 1, 1, mir);
                addEdge(V(i, j + 1), H(i + 1, j), 0, 0, mir);
            } else {
                addEdge(V(i, j), H(i + 1, j), 1, 0, mir);
                addEdge(V(i, j + 1), H(i, j), 0, 1, mir);
            }
        }
    }
     
    std::vector<bool> vis(N);
    std::vector<int> tm(n * m, -1);
     
    for (int x = 0; x < N; x++) {
        if (adj[x][0].first == -1 || adj[x][1].first == -1) {
            int a = x;
            int d = (adj[a][1].first == -1);
            int sum = 0;
            while (a != -1) {
                vis[a] = true;
                tot[a][d] = sum;
                auto [b, w] = adj[a][d ^ 1];
                if (w != -1) {
                    sum += (tm[w] != x);
                    tm[w] = x;
                }
                if (b == -1) {
                    a = -1;
                } else {
                    d = b % 2;
                    a = b / 2;
                }
            }
        }
    }
     
    for (int x = 0; x < N; x++) {
        if (vis[x]) {
            continue;
        }
        int a = x;
        int d = 0;
        int sum = 0;
        do {
            vis[a] = true;
            auto [b, w] = adj[a][d ^ 1];
            if (w != -1) {
                sum += (tm[w] != x);
                tm[w] = x;
            }
            d = b % 2;
            a = b / 2;
        } while (a != x || d != 0);
        do {
            tot[a][0] = tot[a][1] = sum;
            auto [b, w] = adj[a][d ^ 1];
            d = b % 2;
            a = b / 2;
        } while (a != x || d != 0);
    }
     
    int q;
    std::cin >> q;
     
    while (q--) {
        int x, y;
        std::string dir;
        std::cin >> x >> y >> dir;
        int d;
        x--;
        y--;
        int a;
        if (dir == "above") {
            a = H(x, y);
            d = 0;
        } else if (dir == "below") {
            a = H(x + 1, y);
            d = 1;
        } else if (dir == "left") {
            a = V(x, y);
            d = 0;
        } else {
            a = V(x, y + 1);
            d = 1;
        }
        std::cout << tot[a][d] << "\n";
    }
     
    return 0;
}