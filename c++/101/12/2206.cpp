 #include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Edge{
    int x, y, z;
}edges[10010];
int fa[110];

void init() {
    for(int i = 1; i <= 110; i ++) {
        fa[i] = i;
    }
}

bool cmp(Edge x, Edge y) {
    return x.z < y.z;
}

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
 }
 
int main() {
    int n;
    while(scanf("%d", &n) != EOF && n != 0) {
        init();
        int m = n * (n - 1) / 2;
        for(int i = 1; i <= m; i ++) {
            scanf("%d %d %d", &edges[i].x, &edges[i].y, &edges[i].z);
        }
        sort(edges + 1, edges + m + 1, cmp);
        int ans = 0;
        for(int i = 1; i <= m; i ++) {
            int x = edges[i].x, y = edges[i].y, z = edges[i].z;
            int fx = find(x), fy = find(y);
            if(fx == fy) continue;
            else {
                fa[fx] = fy;
                ans += z;
            }
        }
        printf("%d\n", ans); 
    }
    return 0;
}