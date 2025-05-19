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
    ll n, q; cin >> n >> q;
    vector<ll> a(n + 1);
    vector<vector<ll>> p(62, vector<ll> ());
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
        for(ll j = 0; (1ll << j) <= a[i]; j ++ ) {
            if((1ll << j) & a[i]) {
                p[j].push_back(i);
            }
        }
    }
    while(q -- ) {
        ll l, r; cin >> l >> r;
        vector<ll> b(62);
        for(ll j = 0; (1ll << j) <= a[l]; j ++ ) {
            if((1ll << j) & a[l]) {
                b[j] = 1;
            }
        }
        vector<ll> d;
        if(b[0] == 1)
            d.push_back(l);
        for(ll i = 0; i <= 60; i ++ ) {
            vector<ll> d1;
            if(b[i + 1] == 1) d1.push_back(l);
            if(p[i].size() == 0) {
                if(d.size() > 0 && d.back() == r) b[i] = 1;
                d = d1;
                continue;
            }
            for(ll j = 0; j < d.size(); j ++ ) {
                auto pos = upper_bound(p[i].begin(), p[i].end(), d[j]);
                if(pos != p[i].end() && *pos <= r) {
                    d1.push_back(*pos);
                    b[i] = 0;
                } else {
                    if(d.size() > 0 && d.back() == r) 
                        b[i] = 1;
                    else 
                        b[i] = 0; 
                    break;
                }
            }
            d = d1;
        }
        ll ans = 0;
        for(ll i = 0; i <= 61; i ++ ) {
            if(b[i]) ans += (1ll << i);
        }
        cout << ans << "\n";
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