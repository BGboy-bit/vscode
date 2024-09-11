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
    ll n, m, k; cin >> n >> m >> k;
    ll w; cin >> w;
    vector<ll> a(w + 1);
    for(ll i = 1; i <= w; i ++ ) {
        cin >> a[i];
    }
    vector<vector<ll>> d(n + 2, vector<ll>(m + 2, 0)), b(n + 2, vector<ll>(m + 2, 0));
    for(ll i = 1; i <= n - k + 1; i++) {
        for(ll j = 1; j <= m - k + 1; j++) {
            d[i][j]++;
            d[i + k][j]--;
            d[i][j + k]--;
            d[i + k][j + k]++;
        }
    }
    vector<ll> summ;
    for (ll i = 1; i <= n; i ++ ) {
        for(ll j = 1; j <= m; j ++ ) {
            b[i][j] = b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1] + d[i][j];
            summ.push_back(b[i][j]);
        }
    }
    sort(a.begin() + 1, a.end());
    reverse(a.begin() + 1, a.end());
    sort(summ.begin(), summ.end());
    reverse(summ.begin(), summ.end());
    ll ans = 0;
    for(ll i = 1; i <= w; i ++ ) {
        ans += summ[i - 1] * a[i];
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