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

ll dfs(ll u, vector<ll> &a, vector<vector<ll>> &e) {
    if(e[u].empty()) return a[u];
    ll minn = inf;
    for(auto i : e[u]) {
        minn = min(minn, dfs(i, a, e));
    }
    if(u == 1) return a[1] + minn;
    if(minn <= a[u]) return minn;
    else return minn + a[u] >> 1;
}

void Solve() {
    ll n; cin >> n;
    vector<ll> a(n + 1), p(n + 1);
    vector<vector<ll>> e(n + 1);
    for(ll i = 1; i <= n; i ++ ) cin >> a[i];
    for(ll i = 2; i <= n; i ++ ) {
        cin >> p[i]; e[p[i]].push_back(i);
    }
    cout << dfs(1, a, e) << "\n";
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