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
    vector<ll> a(n + 1), b(n + 1);
    // vector<ll> b1(n + 1);
    ll maxx = 0, summ = 0;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i]; summ += a[i];
    }
    for(ll i = 1; i <= n; i ++ ) {
        cin >> b[i]; 
        maxx = max(b[i], maxx);
        // b1[i] = b[i];
    }
    set<ll> s; 
    vector<ll> c;
    vector<ll> qq(q + 1);
    for(ll i = 1, x; i <= q; i ++ ) {
        cin >> qq[i];
        if(!s.count(qq[i])) c.push_back(qq[i]);      
    }
    vector<ll> ans(n + 1);
    
    for(ll i = 1; i <= n; i ++ ) {
        ll res = a[i];
        if(res >= maxx) break;
        for(ll j = 0; j < c.size(); j ++ ) {
            ll x = b[(c[j] + i) % n];
            if(x > res) {
                ans[c[j]] += x - res; res = x; 
            }
            if(x == maxx) break;
        }
    }
    for(ll i = 1; i <= q; i ++ ) {
        summ += ans[qq[i]];
        ans[qq[i]] = 0;
        cout << summ << "\n"; 
    }
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