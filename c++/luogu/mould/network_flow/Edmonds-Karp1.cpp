//�����EK����ʽ��ǰ�ǣ�
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 210;
const int M = 5e5 + 10;
const int inf = 0x3f3f3f3f;
ll n, m, s, t;
ll ans;
ll cnt = 1;//��2��ʼ���

struct edge {//��ʽ��ǰ�Ǽ�¼����һ�������ӵ����б�
    ll to;//Ŀ��ڵ�
    ll nxt;//��һ���ߵ�����
    ll w;//�ߵ�Ȩֵ
}e[M << 1];//����߿������ռ�

ll head[N];//ָ���±�
ll vis[N];//�������
ll pre[N];
ll graph[N][N];
ll dis[N];

void add_edge(ll u, ll v, ll w) {
    cnt ++;
    e[cnt].to = v;
    e[cnt].w = w;
    e[cnt].nxt = head[u];
    head[u] = cnt;
}

bool bfs() {
    memset(vis, 0, sizeof(vis));
    queue<ll> q;
    q.push(s); vis[s] = 1; dis[s] = inf;
    while(!q.empty()) {
        ll pos = q.front(); q.pop();
        for(ll i = head[pos]; i; i = e[i].nxt) {
            if(e[i].w > 0 && !vis[e[i].to]) {
                ll to = e[i].to;
                dis[to] = min(dis[pos], e[i].w);
                pre[to] = i;
                q.push(to);
                vis[to] = 1;
                if(to == t) return 1;
            } 
        }
    }
    return 0;
}
  
void EK() {
    while(bfs()) {
        ll x = t;
        while(x != s) {
            ll i = pre[x];
            e[i].w -= dis[t];
            e[i ^ 1].w += dis[t];
            x = e[i ^ 1].to;//����߼�������߼��ٵ����� 
        }
        ans += dis[t];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> s >> t;
    ll u, v, w;
    for(ll i = 1; i <= m; i ++ ) {
        cin >> u >> v >> w;
        graph[u][v] += w;
    }
    for(ll i = 1; i <= n; i ++ ) {
        for(ll j = 1; j <= n; j ++ ) {
            add_edge(i, j ,graph[i][j]); add_edge(j, i, 0);
        }
    }
    EK();
    cout << ans << "\n";
    return 0;
}

