#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 110;
ll graph[MAX][MAX];
bool vis[MAX][MAX];
bool hid[MAX][MAX];
ll n, m;
struct node {
    ll x, y;
}st, ed;
//ÉÏ ÓÒ ÏÂ ×ó ÄæÊ±Õë
ll dx[4] = {1, 0, -1, 0};
ll dy[4] = {0, 1, 0, -1};

void bfs() {
    st.x = 1;
    st.y = 1;
    queue<node> q;
    q.push(st);
    while(!q.empty()) {
        st = q.front();
        q.pop();
        for(ll i = 0; i < 4; i ++ ) {
            ed.x = st.x + dx[i];
            ed.y = st.y + dy[i];
            if(hid[ed.x][ed.y] == 0 || vis[ed.x][ed.y] == 1) continue;
            vis[ed.x][ed.y] = 1;
            graph[ed.x][ed.y] = graph[st.x][st.y] + 1;
            q.push(ed);
        }
    }
    cout << graph[n][m] << "\n";
}
 
int main() {    
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(ll i = 1; i <= n; i ++ ) {
        for(ll j = 1; j <= m; j ++ ) {
            ll x;
            cin >> x;
            if(x == 0) hid[i][j] = 1;
        }
    }
    bfs();
    return 0;
}