#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 1e6 + 10;

bool ff[MAX];
bool res[MAX];
ll deg[MAX];
ll cnt1, cnt2;

void Solve() {
    ll n, m;
    ll k = 1;
    cin >> n >> m;
    vector<ll> s1(n << 1);
    vector<ll> s2(n << 1);
    vector<ll> g[n << 1];
    vector<ll> g2[n << 1];

    for(ll i = 1; i <= m; i ++ ) {
        ll x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g2[y].push_back(x);
        deg[y] ++ ;
    }
    
    //拓扑排序
    queue<ll> q;
    for(ll i = 1; i <= n; i ++ ) {
        if(deg[i] == 0) q.push(i);
    }
    while(1) {
         //跑完一个子图并且另外子图为环 or 全图一开始就是环
        if(q.empty()) {
            if(cnt1 == n) break ;
            else {
                k = 2;
                for(ll i = 1; i <= n; i ++ ) {
                    if(!res[i] && ! ff[i]) {
                        q.push(i);
                        for(auto j : g2[i]) {
                            if(!res[j] && !ff[i]) {
                                    s2[ ++ cnt2] = j; res[j] = 1;
                                }
                        }
                        s2[++ cnt2] = i; res[i] = 1;
                        break;
                    }
                }
            }
        }
        ll x = q.front(); q.pop();
        s1[++ cnt1] = x; ff[x] = 1;
        for(auto i : g[x]) {
            if(!ff[i]) {
                deg[i] -- ;
                if(deg[i] == 0) {
                    q.push(i);
                }
            }
            //形成环
            else {
                if(!res[x]) {
                    s2[++ cnt2] = x; res[x] = 1;
                }
                if(!res[i]) {
                    s2[++ cnt2] = i; res[i] = 1;
                }
            }
        }
    }
    cout << k << "\n";
    for(ll i = 1; i <= n; i ++ ) cout << s1[i] << " ";
    cout << "\n";
    if(k == 2) {
        for(ll i = 1; i <= cnt2; i ++ ) cout << s2[i] << " ";
        for(ll i = 1; i <= n; i ++ ) if(!res[i]) cout << i << " ";
        cout << "\n";
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
