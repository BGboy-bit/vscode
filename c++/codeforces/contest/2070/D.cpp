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

ll ans, mxd;

void dfs1(ll x, ll dp, vector<vector<ll>> &a, vector<vector<ll>> &dep, vector<ll> &d) {
    for(auto son : a[x]) {
        dep[dp + 1].push_back(son); d[son] = dp + 1;
        mxd = max(dp + 1, mxd);
        dfs1(son, dp + 1, a, dep, d);
    }
}

void Solve() {
    ll n; cin >> n;
    ans = 0; mxd = 0;
    vector<ll> fa(n + 1), d(n + 1), cnt(n + 1, 1);
    vector<vector<ll>> a(n + 1), dep(n + 1);
    for(ll i = 2; i <= n; i ++ ) {
        cin >> fa[i];
        a[fa[i]].push_back(i);
    }
    dfs1(1, 0, a, dep, d);
    ll sum = dep[mxd].size();
    for(ll i = mxd - 1; i >= 1; i -- ) {
        for(auto x : dep[i]) {
            cnt[x] = (sum + 1) % mod;
            ll s1 = 0;
            for(auto y : a[x]) {
                s1 = (cnt[y] + s1) % mod;
            }
            cnt[x] = (cnt[x] - s1 + mod) % mod;
        }
        sum = 0;
        for(auto x : dep[i]) {
            sum = (cnt[x] + sum) % mod;
        }
    }
    cout << (sum + 1) % mod << "\n";
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