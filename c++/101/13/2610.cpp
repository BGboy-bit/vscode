// #include<bits/stdc++.h>
// using namespace std;

// const int MAX = 33;
// int n, m;
// int graph[MAX][MAX];//AOE图
// int f[MAX];//判断是否到过此点

// string str[10000];//关键路径字典化
// int cnt;//当前关键路径组数
// int maxx;//最大权值
// int st, ed;//源点与汇点

// void dfs(int pos, int sum, vector<int> v1) {
//     if(pos == ed) {
//         if(sum >= maxx) {
//             if(sum > maxx) {
//                 for(int i = 0; i < cnt; i ++ )  str[i].erase();
//                 cnt = 0;
//                 maxx = sum;
//             }
//             for(int i = 0; i < v1.size(); i ++ ) str[cnt] += v1[i] + '0';
//             cnt ++;
//         }
//         return;
//     }

//     for(int i = 1; i <= n; i ++ ) {
//         if(f[i]) continue;
//         if(graph[pos][i] != 0) {
//             v1.push_back(i);
//             f[i] = 1;
//             dfs(i, sum + graph[pos][i], v1);
//             f[i] = 0;
//             v1.pop_back();
//          }   
//     }  
// }

// int main() {   
//     while(scanf("%d %d", &n, &m) != EOF) {
//         //初始化
//         memset(graph, 0, sizeof(graph));
//         for(int i = 0; i < cnt; i ++ )  str[i].erase();
//         cnt = 0;
//         maxx = 0;
//         vector<int> v1;//记录当前路径
//         // vector<int>().swap(v1);

//         int x, y, z;
//         for(int i = 1; i <= m; i ++ ) {
//             scanf("%d %d %d", &x, &y, &z);
//             if(z > graph[x][y]) graph[x][y] = z;
//         }
//         for(int i = 1; i <= n; i ++ ) {
//             bool gg = 1, hh = 1;
//             for(int j = 1; j <= n; j ++ ) {
//                 if(i == j) continue;
//                 if(graph[i][j] != 0) gg = 0;
//                 if(graph[j][i] != 0) hh = 0;
//             } 
//             if(gg && !hh) ed = i;
//             if(!gg && hh) st = i;
//         } 
//         v1.push_back(st);
//         f[st] = 1;
//         dfs(st, 0, v1);
//         if(cnt == 0) {printf("-1"); return 0;}
//         sort(str, str + cnt);
//         printf("%d\n", maxx);
//         for(int i = 0; i < str[0].size() - 1; i ++ ) {
//             printf("%c %c\n", str[0][i], str[0][i + 1]);
//         }
//     }
//     return 0;
// }


#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define N 35

int Graph[N][N];

int num_node;

int num_edge;

void dfs(int cur, int cur_count, int cur_weight, int end, char path[], int* ans_weight, char ans_path[]) {
    // 如果抵达终点则记录结果并退出
    if (cur == end) {
        // 因为这里的dfs按节点编号从小到大搜索
        // 因此最先搜索到的关键路径一定是字典序最小的！！！
        if (*ans_weight < cur_weight) {
            *ans_weight = cur_weight;
            strcpy(ans_path, path);
        }
        return;
    }
    for (int i = 1; i <= num_node; i++) {
        if (Graph[cur][i] != 0) {
            path[cur_count] = i;
            path[cur_count + 1] = 0;
            dfs(i, cur_count + 1, cur_weight + Graph[cur][i], end, path, ans_weight, ans_path);
        }
    }
}

int main() {
    while (~scanf("%d %d", &num_node, &num_edge)) {
        memset(Graph, 0, sizeof(Graph));
        // 读取图的数据
        for (int i = 0; i < num_edge; i++) {
            int from, to, weight;
            scanf("%d %d %d", &from, &to, &weight);
            Graph[from][to] = weight;
        }
        // 确定起点（入度为0）和终点
        int start = -1;
        int end = -1;
        for (int i = 1; i <= num_node; i++) {
            int cnt1 = 0;  // 统计节点i的入度
            int cnt2 = 0;  // 统计节点i的出度
            for (int j = 1; j <= num_node; j++) {
                if (Graph[j][i] != 0) cnt1++;
                if (Graph[i][j] != 0) cnt2++;
                if (cnt1 > 0 && cnt2 > 0) break;
            }
            if (cnt1 == 0) start = i;
            if (cnt2 == 0) end = i;
            if (start != -1 && end != -1) break;
        }
        // dfs整张图
        int ans_weight = 0;
        char path[N] = {start, 0};
        char ans_path[N] = {0};
        dfs(start, 1, 0, end, path, &ans_weight, ans_path);
        // 输出答案
        printf("%d\n", ans_weight);
        int last = start;
        int next;
        for (int i = 1; ans_path[i]; i++) {
            printf("%d %d\n", ans_path[i - 1], ans_path[i]);
        }
       
    }
}