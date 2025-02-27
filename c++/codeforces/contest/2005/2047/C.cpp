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
    ll n; cin >> n;
    vector<pair<ll, ll>> a(2 * n + 1);
    for(ll i = 1; i <= 2 * n; i ++ ) {
        cin >> a[i].first; a[i].second = i;
    }
    sort(a.begin() + 1, a.end());
    ll ans = 0, cnt = 0;
    vector<ll> res(n + 1);
    for(ll i = 1; i <= 2 * n; i ++ ) {
        ans += a[i].first;
        if(cnt == n - 1) continue;
        // ll x;
        // if(a[i].second <= n) x = a[i].second;
        // else x = a[i].second - n;
        ll x = a[i].second <= n ? a[i].second : a[i].second - n;
        if(res[x] == 0) {
            ans -= a[i].first; res[x] = 1; cnt ++ ; continue;
        }
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