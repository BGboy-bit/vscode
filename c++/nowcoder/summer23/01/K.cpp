//参考https://ac.nowcoder.com/acm/contest/view-submission?submissionId=62804852
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int inf = 0x3f3f3f3f;
const int MAX = 2e5 + 10;

ll n, m, k;
vector<ll> e[MAX];//邻接边


void Solve() {
    cin >> n >> m >> k;
    vector<ll> d(n, -1);//与‘1’的最短距离
    vector<ll> deg(n, 0);//邻接点
    for(ll i = 1; i <= m; i ++ ) {
        ll u, v;
        cin >> u >> v;
        u -- ; v -- ;
        e[u].push_back(v); e[v].push_back(u);
        deg[u] ++ ; deg[v] ++ ;
    }

    //bfs
    queue<ll> q;
    d[0] = 0; q.push(0);
    while(!q.empty()) {
        ll dot = q.front(); q.pop();
        for(auto i : e[dot]) {
            if(d[i] == -1) {
                d[i] = d[dot] + 1;
                q.push(i);
                deg[i] -- ; deg[dot] -- ;       
            }
        }
    }
    
    ll ans = 1;//‘1’本身
    for(ll i = 1; i < n; i ++ ) {
        if(d[i] >= 0 && d[i] <= k) {
            ans += deg[i] * (k - d[i]) + 1;//计算不在bfs树上的边，+1为i本身这个点
            if((e[i].size() == 1) && (i != 0)) ans += k - d[i];//没有连接非树边则在树边上加点
        }
    }
    cout << ans << "\n";
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