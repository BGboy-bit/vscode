#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
int n, m;
int graph[35][35];
int st, ed;
int maxx;
int sna;//the length of ans
bool vis[35];

void dfs(int pos, int sum, char load[], int cnt, char ans[]) {
    if(pos == ed) {
        if(sum > maxx) {
            maxx = sum;
            strcpy(ans, load);
            sna = cnt;
        } 
        return;
    }

    for(int i = 1; i <= n; i ++ ) {
        if(vis[i] || graph[pos][i] == 0) continue;
        vis[i] = 1;
        load[cnt] = i;
        load[cnt + 1] = 0;
        dfs(i, sum + graph[pos][i], load, cnt + 1, ans);
        vis[i] = 0;
    }    
}


int main() {
    while(scanf("%d %d", &n, &m) != EOF) {
        memset(graph, 0, sizeof(graph));
        maxx = 0;
        st = 0; ed = 0;
        for(int i = 1; i <= m; i ++ ) {
            int sv, ev, w;
            scanf("%d %d %d", &sv, &ev, &w);
            graph[sv][ev] = w;
        }
        
        for(int i = 1;i <= n; i ++ ) {
            int hh = 0, tt = 0;
            for(int j = 1; j <= n; j ++ ) {
                if(graph[i][j] > 0) hh ++ ;
                else if(graph[j][i] > 0) tt ++ ; 
            }
            if(hh == 0) ed = i;
            else if(tt == 0) st = i;
        }
       
        char ans[35] = {st};
        char load[35] = {st};
        dfs(st, 0, load, 1, ans);
        printf("%d\n", maxx);
        for(int i = 0; i < sna - 1; i ++ ) printf("%d %d\n", ans[i], ans[i + 1]);
    }
    return 0;
}