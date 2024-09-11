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
    ll n, k; cin >> n >> k;
    vector<ll> a(n + 1);
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    reverse(a.begin() + 1, a.end());
    for(ll i = 2; i <= n; i += 2) {
        ll b = a[i];
        a[i] += min(k, a[i - 1] - a[i]);
        k -= min(k, a[i - 1] - b);
        if(k == 0) break;
    }
    ll ans = 0;
    for(ll i = 1; i <= n; i ++ ) {
        if(i % 2 == 1) ans += a[i];
        else ans -= a[i];
    }
    cout << ans << "\n";
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