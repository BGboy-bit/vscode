#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
typedef array<ll, 2> PII; // vector<PII> a(n + 1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int maxn = 2e5 + 10;
bool multi = 1;

void dfs(ll pos, ll dep, vector<ll> &deep, vector<vector<ll>> &a, vector<vector<ll>> &b, ll &maxx) {
    deep[pos] = dep;
    maxx = max(maxx, dep);
    b[dep].push_back(pos);
    for(auto nxt : a[pos]) {
        if(deep[nxt] == -1) {
            dfs(nxt, dep + 1, deep, a, b, maxx);
        }
    }
}

void Solve() {
    ll n, st, en; cin >> n >> st >> en;
    vector<vector<ll>> a(n + 1), b(n + 1);
    vector<ll> deep(n + 1, -1);
    for(ll i = 1; i < n; i ++ ) {
        ll u, v; cin >> u >> v;
        a[u].push_back(v); a[v].push_back(u);
    }
    ll maxx = 0;
    dfs(en, 0, deep, a, b, maxx);
    for(ll i = maxx; i >= 0; i -- ) {
        for(auto j : b[i]) {
            cout << j << " ";
        }
    }
    cout << "\n";
}


signed main() {
    // freopen("test.in","r",stdin);  
    // freopen("code.out","w",stdout);    
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}