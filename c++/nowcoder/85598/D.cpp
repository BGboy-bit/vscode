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

const int N = 550;
ll dp[N][N], pre[N], suf[N];

void Solve() {
    ll n, L, R; cin >> n >> L >> R;
    string s; cin >> s; s = '!' + s;
    for(ll i = 1; i <= n; i ++ ) {
        if(s[i] == '0')
            pre[i] = pre[i - 1] + 1;
        else
            pre[i] = pre[i - 1];
    }
    for(ll i = n; i >= 1; i -- ) {
        if(s[i] == '1')
            suf[i] = suf[i + 1] + 1;
        else 
            suf[i] = suf[i + 1];
    }
    for(ll len = 1; len <= n; len ++ ) {
        for(ll l = 1; l + len - 1 <= n; l ++ ) {
            ll r = l + len - 1;
            for(ll j = l; j < r; j ++ ) {
                ll x0 = pre[j] - pre[l - 1], x1 = suf[j + 1] - suf[r + 1];
                ll x = abs(x0 - x1);
                if(x >= L && x <= R)
                    dp[l][r] = max(dp[l][r], dp[l][j] + dp[j + 1][r] + 1); 
            }
        } 
    } 
    cout << dp[1][n] << "\n";
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