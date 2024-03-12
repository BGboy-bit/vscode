 #include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int fa[1010], f[1010];

void init() {
    for(int i = 1; i <= 1000; i ++) {
        fa[i] = i;
        f[i] = 0;
    }
}

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
 }
 
int main() {
    int n;
    while(scanf("%d", &n) != EOF && n != 0) {
        init();
        int m, x, y;
        scanf("%d", &m);
        for(int i = 1; i <= m; i ++) {
            scanf("%d %d", &x, &y);
            int fx = find(x), fy = find(y);
            fa[fx] = fy;
        }
        int cnt = 0;
        for(int i = 1; i <= n; i ++) {
            int fi = find(i);
            if(!f[fi]) {
                cnt ++;
                f[fi] = 1;
            }           
        }
        printf("%d\n", cnt - 1);
    }
    return 0;
}