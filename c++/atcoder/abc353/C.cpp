#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
typedef array<ll, 2> PII; // vector<PII> a(n + 1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 0;

void Solve() {
    ll n; cin >> n;
    //n = 3e5;
    vector<ll> a(n + 1);
    vector<ll> b(n + 1);
    b[0] = 0;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for(ll i = 1; i <= n; i ++ ) {
        b[i] = b[i - 1] + a[i];
    }
    ll ans = 0;
    ll R = n;
    ll m = 1e8;
    for(ll i = 1; i < n; i ++ ) {
        ll l = i, r = R;
        while(l < r) {
            ll md = (l + r + 1) / 2;
            if(a[md] + a[i] < m) {
                l = md;
            } else r = md - 1;
        }
        R = l;
        ans += b[l] - b[i] + a[i] * (l - i) + (b[n] - b[l] + a[i] * (n - l)) - (n - l) * m;
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