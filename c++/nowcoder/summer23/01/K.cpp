//�ο�https://ac.nowcoder.com/acm/contest/view-submission?submissionId=62804852
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int inf = 0x3f3f3f3f;
const int MAX = 2e5 + 10;

ll n, m, k;
vector<ll> e[MAX];//�ڽӱ�


void Solve() {
    cin >> n >> m >> k;
    vector<ll> d(n, -1);//�롮1������̾���
    vector<ll> deg(n, 0);//�ڽӵ�
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
    
    ll ans = 1;//��1������
    for(ll i = 1; i < n; i ++ ) {
        if(d[i] >= 0 && d[i] <= k) {
            ans += deg[i] * (k - d[i]) + 1;//���㲻��bfs���ϵıߣ�+1Ϊi���������
            if((e[i].size() == 1) && (i != 0)) ans += k - d[i];//û�����ӷ��������������ϼӵ�
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