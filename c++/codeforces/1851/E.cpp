#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;

ll n, k;
ll c[MAX];
ll p[MAX];
vector<ll> v[MAX];
bool ff[MAX];
ll c2[MAX];

ll dfs(ll pos) {
    if(ff[pos]) return c[pos];
    for(auto i : v[pos]) {
        
        if(!ff[i]) c2[pos] += dfs(i);
        else c2[pos] += c[i];
    }
    ff[pos] = 1;
    c[pos] = min(c[pos], c2[pos]);
    return c[pos];
}

void Solve() {
    cin >> n >> k;
    for(ll i = 1; i <= n; i ++ ) {
        ff[i] = 0; c2[i] = 0; v[i].clear();
    }
    for(ll i = 1; i <= n; i ++ ) cin >> c[i];
    for(ll i = 1; i <= k; i ++ ) {
        ll pos;
        cin >> pos;
        ff[pos] = 1;
        c[pos] = 0;
    }
    for(ll i = 1; i <= n; i ++ ) {
        ll m;
        cin >> m;
        if(m == 0) ff[i] = 1;
        else {
            ll pos;
            for(ll j = 1; j <= m; j ++ ) {
                cin >> pos;
                if(ff[pos]) c2[i] += c[pos];
                else v[i].push_back(pos);
            }
            if(v[i].size() == 0) {
                c[i] = min(c[i], c2[i]);
                ff[i] = 1;
            }
        } 
    }

    for(ll i = 1; i <= n; i ++ ) {
        if(!ff[i]) dfs(i);
        cout << c[i] << " ";
    }
    cout << "\n";
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