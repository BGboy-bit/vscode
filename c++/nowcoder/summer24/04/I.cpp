#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
typedef array<ll, 2> PII; // vector<PII> a(n+1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 0;

const int N = 1e6 + 10;
struct ed {
    ll u, v;
}e[N];
bool cmp(ed x, ed y) {
    if(x.u == y.u) {
        return x.v < y.v;
    }
    else return x.u > y.u;
}

void Solve() {
    ll n, m; cin >> n >> m;
    for(ll i = 1; i <= m; i ++ ) {
        ll u, v; cin >> u >> v;
        e[i].u = u, e[i].v = v;
    }
    sort(e + 1, e + m + 1, cmp);
    ll ans = n;
    ll l = -1, res = n, r = 0, res1 = -1;
    for(ll i = 1; i <= m; i ++ ) {
        ll u = e[i].u, v = e[i].v;
        if(u != l) {
            if(res1 != -1) {
                res = res1;
                res1 = -1;
            }
            l = u;
            if(v != u + 1) {
                res = -1;
            } else {
                r = v;
                ans ++ ;
                if(res == -1) res = r;
                res1 = r;
            }
        } else {
            if(v == r + 1) {
                if(v <= res) {
                    ans ++ ;
                    r ++ ;
                    res1 ++ ;
                } 
            }
        }
    }
    cout << ans << "\n";
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