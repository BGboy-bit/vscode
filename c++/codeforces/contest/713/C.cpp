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

const int N = 3030;
ll a[N], b[N];
ll dp[N][N];

void Solve() {
    ll n; cin >> n;
    for(ll i = 1; i <= n; i ++ ) cin >> a[i];
    for(ll i = 1; i <= n; i ++ ) {
        a[i] = a[i] - i;
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    for(ll i = 1; i <= n; i ++ ) {
        ll minv = inf;
        for(ll j = 1; j <= n; j ++ ) {
            minv = min(minv, dp[i - 1][j]);
            dp[i][j] = minv + abs(a[i] - b[j]);
        }
    }
    ll ans = inf;
    for(ll i = 1; i <= n; i ++ ) ans = min(ans, dp[n][i]);
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