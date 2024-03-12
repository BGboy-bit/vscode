#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll v, e;
char a[1000];
char s[100];
ll cnt;
map<char, ll> c;
map<ll, char> d;
bool f;
bool vis[25];
bool graph[25][25];

void dfs(ll pos) {
    vis[pos] = 1;
    for(ll i = 0; i < v; i ++ ) {
        if(graph[pos][i] && !vis[i]) {
            vis[i] = 1;
            char maxx = max(d[pos], d[i]);
            char minn = min(d[pos], d[i]);
            a[cnt ++ ] = minn;
            a[cnt ++ ] = maxx;
            dfs(i);
        }
    }
}

int main() {
    scanf("%lld", &v);
    for(ll i = 0; i < v; i ++ ) {
        scanf("%s", s);
        c[s[0]] = i;
        d[i] = s[0];
    }
    scanf("%lld", &e);
    char x, y;
    for(ll i = 0; i < e; i ++ ) {
        scanf("%s", s);
        sscanf(s, "%c,%c", &x, &y);
        graph[c[x]][c[y]] = 1;
        graph[c[y]][c[x]] = 1;      
    }
    dfs(0);
    for(ll i = 0; i < v; i ++ ) {
        if(!vis[i]) {
            printf("ERROR\n");
            f = 1;
            break;
        }
    } 
    if(!f) {
        for(ll i = 0; i < cnt; i += 2)  
        printf("%c,%c\n", a[i], a[i + 1]);
    }
    return 0;
}


// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <stdbool.h>
// #define N 100

// int nameToId[0x7f];

// char idToName[N];

// int Graph[N][N];

// char minChar(char c1, char c2) {
//     return c1 > c2 ? c2 : c1;
// }

// char maxChar(char c1, char c2) {
//     return c1 < c2 ? c2 : c1;
// }

// void dfs(int cur, int num_node, bool vis[], int* idx_ans, char ans[]) {
//     vis[cur] = true;
//     for (int i = 0; i < num_node; i++) {
//         if (Graph[cur][i] && !vis[i]) {
//             ans[(*idx_ans)++] = minChar(idToName[cur], idToName[i]);
//             ans[(*idx_ans)++] = maxChar(idToName[cur], idToName[i]);
//             dfs(i, num_node, vis, idx_ans, ans);       
//         }
//     }
// }

// int main() {
//     char buf[N];
//     int num_node;
//     int num_edge;
//     scanf("%d", &num_node);
//     // �����ڵ��źͽڵ����ݵ�ӳ���ϵ
//     for (int i = 0; i < num_node; i++) {
//         char name;
//         scanf("%s", buf);
//         name = buf[0];
//         nameToId[name] = i;
//         idToName[i] = name;
//     }
//     // �ڽӾ���ͼ
//     scanf("%d", &num_edge);
//     for (int i = 0; i < num_edge; i++) {
//         char from, to;
//         int from_id, to_id;
//         scanf("%s", buf);
//         sscanf(buf, "%c,%c", &from, &to);
//         from_id = nameToId[from];
//         to_id = nameToId[to];
//         Graph[from_id][to_id] = 1;
//         Graph[to_id][from_id] = 1;
//     }
//     bool vis[N];  
//     int idx_ans = 0;
//     char ans[N];
//     memset(vis, false, sizeof(vis));  
//     // ��ͼ����dfs,����dfs������
//     dfs(0, num_node, vis, &idx_ans, ans);
//     // �ж��Ƿ�����ͨͼ
//     int isConnected = true;
//     for (int i = 0; i < num_node; i++) {
//         if (!vis[i]) {
//             isConnected = false;
//             break;
//         }
//     }
//     if (isConnected) {
//         for (int i = 0; i < idx_ans; i += 2) {
//             printf("%c,%c\n", ans[i], ans[i + 1]);
//         }        
//     } else {
//         puts("ERROR");
//     }
// }