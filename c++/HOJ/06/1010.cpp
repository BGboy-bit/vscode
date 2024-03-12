#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 10;

ll head[MAX];//每个点连接的第一条边的索引
struct edge {//链式向前星记录的是一个点连接的所有边
    ll to;//目标节点
    ll nxt;//下一条边的索引
}e[MAX];//反向边添加
ll cnt;//边的总数，从1开始计数
void add_edge(ll u, ll v) {
    cnt ++;
    e[cnt].to = v;
    e[cnt].nxt = head[u];
    head[u] = cnt;
}

void Solve() {
    cnt = 0;
    ll cir_maxx = 0;
    ll n, q;
    cin >> n >> q;
    vector<ll> col(n << 1, 0);//标记处于第几个环
    vector<ll> cir[n << 1];//记录环
    vector<ll> k(n + 1);
    vector<ll> b(n + 1);
    for(ll i = 1; i <= n; i ++ ) cin >> k[i];
    for(ll i = 1; i <= n; i ++ ) cin >> b[i];
    ll maxx = 0;
    for(ll i = 1; i <= n; i ++ ) {
        ll p; cin >> p;
        add_edge(i, p);
        maxx = max(maxx, p); 
        if(maxx == i) {
            cir_maxx ++ ;
            col[p] = cir_maxx;
            ll v = e[head[p]].to;
            cir[cir_maxx].emplace_back(v);
            col[v] = cir_maxx;
            while(p != v) {
                v = e[head[v]].to;
                col[v] = cir_maxx;
                cir[cir_maxx].emplace_back(v);
            }
        }
    }
    while(q -- ) {
        ll x, l, y;
        cin >> x >> l >> y;
        if(col[x] == 0) {
            while(col[x] == 0) {
                x = e[head[x]].to;
                y = (y * k[x] + b[x]) % mod;
                l -- ;
            }
        }
        ll si = cir[col[x]].size();
        vector<ll> K(si, 0);
        vector<ll> B(si, 0);
        ll pos;
        for(ll i = 0; i < si; i ++ ) {
            if(cir[col[x]][i] == x) {
                pos = i; break;
            }
        }

        ll i;
        if(pos == si - 1) i = 0;
        else i = pos + 1;
        for(ll cnt = 0; cnt < si - 1; i ++ , cnt ++ ) {
            if(cnt == 0) {
                K[cnt] = k[cir[col[x]][i]];
                B[cnt] = b[cir[col[x]][i]];    
            }
            else {
                ll u = k[cir[col[x]][i]] * K[cnt - 1] % mod;
                K[cnt] = u;
                ll v = (b[cir[col[x]][i]] + B[cnt - 1] * k[cir[col[x]][i]]) % mod;
                B[cnt] = v;
            }
            if(i == si - 1) i = -1;
        }
        ll u = k[cir[col[x]][pos]] * K[si - 2] % mod;
        K[si - 1] = u;
        ll v = (b[cir[col[x]][pos]] + B[si - 2] * k[cir[col[x]][pos]]) % mod;
        B[si - 1] = v;
        ll num = l / si;
        for(i = 1; i <= num; i ++ ) y = (y * K[si - 1] + B[si - 1]) % mod; 
        num = l % si;
        if(num != 0) y = (y * K[num - 1] + B[num - 1]) % mod;
        cout << y << "\n";
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}