#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 1e6 + 10;

ll n, m;
vector<ll> g[MAX];
ll deg[MAX];//点的入度
vector<ll> s;//记录路径
bool ff[MAX];//标记点是否到达

void Solve() {
    cin >> n >> m;
    ll k = 1;
    for(ll i = 1; i <= m; i ++ ) {
        ll x, y;
        cin >> x >> y;
        g[x].push_back(y);
        deg[y] ++ ;
    }

    //拓扑排序判断是否成环
    queue<ll> q;
    for(ll i = 1; i <= n; i ++ ) {
        if(deg[i] == 0) q.push(i); 
    }
    if(q.empty()) k = 2; 
    else {
        while(!q.empty()) {
            ll dot = q.front(); q.pop(); s.push_back(dot);
            for(auto i : g[dot]) {
                if(!ff[i]) {
                    deg[i] -- ;
                    if(deg[i] == 0) q.push(i);
                }   
            }
        }
        if(s.size() == n) k = 1;
        else k = 2;
    }

    if(k == 1) {
        cout << "1" << "\n";
        for(auto i : s) cout << i << " ";
        cout << "\n";
    }
    else {
        cout << "2" << "\n";
        for(ll i = 1; i <= n; i ++ ) cout << i << " ";
        cout << "\n";
        for(ll i = n; i >= 1; i -- ) cout << i << " ";
    }
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