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

void dfs(ll u, ll v, vector<ll> &fa) {
    cout << "? " << u << " " << v << endl;
    ll x; cin >> x;
    if(x == u) {
        fa[v] = u; return ;
    }
    if(fa[x] == x) 
        dfs(u, x, fa); 
    if(fa[v] == v)
        dfs(x, v, fa); 
}

void Solve() {
    ll n; cin >> n;
    vector<ll> fa(n + 1);
    for(ll i = 1; i <= n; i ++ ) fa[i] = i;
    for(ll i = 2; i <= n; i ++ ) {
        if(fa[i] == i)
            dfs(1, i, fa);
    }
    cout << "! ";
    for(ll i = 2; i <= n; i ++ ) {
        cout << i << " " << fa[i] << " ";
    }
    cout << endl;
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