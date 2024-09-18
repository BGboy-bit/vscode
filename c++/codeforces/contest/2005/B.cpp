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

void Solve() {
    ll n, m, q; cin >> n >> m >> q;
    vector<ll> a(m + 1);
    for(ll i = 1; i <= m; i ++ ) {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    while(q -- ) {
        ll p; cin >> p;
        if(p < a[1]) {
            cout << a[1] - 1 << "\n";
        } else if(p > a[m]) {
            cout << n - a[m] << "\n";
        } else {
            ll x = lower_bound(a.begin() + 1, a.begin() + m + 1, p) - a.begin();
            cout << (a[x] + a[x - 1]) / 2 - a[x - 1] << "\n";
        }
    }
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