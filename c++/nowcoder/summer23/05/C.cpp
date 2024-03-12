#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int N = 3010;
const int M = N * N / 2;

ll n, m;
ll dfn[N], dfn_maxx;//��ʾ�������dfsʱ�ǵڼ������ѵ���
ll low[N];//��ʾ������Լ�������ڵ��������е���dfn��С��ֵ
stack<ll> st;
ll id[N], id_maxx;//��������λ�ڵ�ǿ��ͨ����
ll num[N];// ���ǿ��ͨ�����еĵ������
ll out[N];//ÿ��ǿ��ͨ�����ĳ���
ll vis[N];//����Ƿ���ջ��

ll head[N];//ÿ�������ӵĵ�һ���ߵ�����
struct edge {//��ʽ��ǰ�Ǽ�¼����һ�������ӵ����б�
    ll to;//Ŀ��ڵ�
    ll nxt;//��һ���ߵ�����
}e[M];
ll cnt;//�ߵ���������1��ʼ����
void add_edge(ll u, ll v) {
    cnt ++;
    e[cnt].to = v;
    e[cnt].nxt = head[u];
    head[u] = cnt;
}

void tarjan(ll u) {
    low[u] = dfn[u] = ++ dfn_maxx;
    vis[u] = 1;
    st.push(u);
    for(ll i = head[u]; i; i = e[i].nxt) {
        ll v = e[i].to;
        if(dfn[v] != 0) {
            if(vis[v]) low[u] = min(low[u], dfn[v]);
        }
        else {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
    }
    //�ҵ�һ��ǿ��ͨ������ͷ�ڵ�
    if(dfn[u] == low[u]) {
        id[u] = ++ id_maxx;
        num[id_maxx] ++ ;
        vis[u] = 0;
        while(st.top() != u) {
            ll v = st.top(); st.pop();
            vis[v] = 0;
            id[v] = id_maxx;
            num[id_maxx] ++ ;
        }
        st.pop();
    }
}

void Solve() {
    cin >> n;
    for(ll i = 1; i <= n; i ++ ) {
        for(ll j = 1; j <= n; j ++ ) {
            ll f; cin >> f;
            if(f == 1) {
                add_edge(i, j);
            }
        }
    }
    //tarjan��ǿ��ͨ����
    for(ll i = 1; i <= n; i ++ ) {
        if(!dfn[i]) tarjan(i);
    }
    bool ff = 1;
    for(ll i = 1; i <= id_maxx; i ++ ) {
        if(num[i] < 2) {
            ff = 0; break;
        }
    }
    if(ff) cout << n << "\n";
    else cout << n - 1 << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    // cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}