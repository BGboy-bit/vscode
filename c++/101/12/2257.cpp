// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;

// struct Edge {
//     int x, y;
// }edges[10000];
// int n, m;
// int f[10000];
// bool AC;
// int st;

// void dfs(int x, int cnt) {
//     if(AC) return;
//     else if(cnt == m && x == st) {
//         AC = 1;
//         return;
//     } 
//     for(int i = 1; i <= m; i ++) {
//         if(f[i]) continue; 
//         if(edges[i].x == x) {
//             f[i] = 1;
//             dfs(edges[i].y, cnt + 1);
//             f[i] = 0;
//         }
//         if(edges[i].y == x) {
//             f[i] = 1;
//             dfs(edges[i].x, cnt + 1);
//             f[i] = 0;
//         }
//     }
// }

// int main() {
//     while(scanf("%d %d", &n ,&m) != EOF && n != 0) {
//         AC = 0;
//         //memset(f, 0, sizeof(f));
//         for(int i = 1; i <= m; i ++) {
//             scanf("%d %d", &edges[i].x, &edges[i].y);
//         }
//         for(int i = 1; i <= m; i ++) {
//             f[i] = 1;
//             st = edges[i].x;
//             dfs(edges[i].y, 1);
//             st = edges[i].y;
//             dfs(edges[i].x, 1);
//             f[i] = 0;
//         }
//         if(AC) printf("YES\n");
//         else printf("NO\n");
//     }
//     return 0;
// }
// #include<bits/stdc++.h>
// using namespace std;

// int cnt[1010];
// int n, m, x, y;
// bool AC;

// int main() {
//     while(scanf("%d %d", &n, &m) != EOF && n != 0) {
//         AC = 0;
//         memset(cnt, 0, sizeof(cnt));
//         for(int i = 1; i <= m; i ++) {
//             scanf("%d %d", &x, &y);
//             cnt[x] ++;
//             cnt[y] ++;
//         }
//         for(int i = 1; i <= n; i ++) {
//             if(cnt[i] % 2 != 0) {
//                 AC = 1;
//                 break;
//             }
//         }
//         if(AC) printf("NO\n");
//         else printf("YES\n");
//     }
//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;

vector<int> adj[1010];
int n, m, x, y;
bool visited[1010];

void dfs(int node) {
    visited[node] = true;
    for (int i = 0; i < adj[node].size(); i++) {
        int nextNode = adj[node][i];
        if (!visited[nextNode]) {
            dfs(nextNode);
        }
    }
}

bool isConnected() {
    memset(visited, false, sizeof(visited));
    dfs(1);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            return false;
        }
    }
    return true;
}

bool checkEuler() {
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() % 2 != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    while (scanf("%d %d", &n, &m) != EOF && n != 0) {
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
        }

        for (int i = 1; i <= m; i++) {
            scanf("%d %d", &x, &y);
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        if (checkEuler() && isConnected()) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
