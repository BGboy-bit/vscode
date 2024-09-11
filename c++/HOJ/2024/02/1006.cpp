#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
typedef array<ll, 2> PII; // vector<PII> a(n+1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 5e5 + 10;
bool multi = 1;

struct frac { // x / y
    ll x, y;
};
bool comp(frac u, frac v) {
    ll u1 = u.x * v.y, v1 = u.y * v.x;
    return u1 < v1;
}
frac add(frac u, frac v) {
    frac f;
    f.x = u.x * v.y + u.y + v.x;
    f.y = u.y * v.y;
    return f;
}

vector<ll> e[MAX];
vector<frac> ff;

frac dfs(ll u, ll fa) {
    frac f = ff[u];
    frac f1 = ff[u];
    for(ll i = 0; i < e[u].size(); i ++ ) {
        if(e[u][i] != fa) {
           frac f2 = add(f1, dfs(e[u][i], u));
           if(comp(f, f2)) f = f2; 
        }
    }
    return f;
}

void Solve() {
    ll n; cin >> n;
    for(ll i = 1; i < n; i ++ ) {
        ll u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    frac f = {0, 0};
    ff.push_back(f);
    for(ll i = 1; i <= n; i ++ ) {
        ll p; cin >> p;
        frac f = {15, p};
        ff.push_back(f);
    }
    f = dfs(1, 1);
    ll z = __gcd(f.x, f.y);
    f.x = f.x / z;
    f.y = f.y / z;
    cout << f.x << " " << f.y << "\n";
    for(ll i = 1; i <= n; i ++ ) e[i].clear();
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}