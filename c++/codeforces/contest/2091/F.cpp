#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int mod = 998244353;


void Solve() {
    ll n, m, d; cin >> n >> m >> d;
    vector<vector<ll>> g(n + 1, vector<ll> (m + 1)), a(n + 1, vector<ll> (m + 1));
    for(ll i = 1; i <= n; i ++ ) {
        string s; cin >> s;
        for(ll j = 0; j < m; j ++ ) {
            if(s[j] == 'X') g[i][j + 1] = 1; 
        }
    }
    vector<ll> len(n + 1, -1);
    for(ll i = 0; i <= n; i ++ ) {
        for(ll j = 0; j <= m; j ++ ) {
            if(j * j + i * i == d * d) {
                len[i] = j; break;
            } else if(j * j + i * i > d * d) {
                len[i] = j - 1; 
                break;
            }
        }
    }
    ll ans = 0;
    for(ll i = 1; i <= n; i ++ ) {
        vector<ll> vis = a[i];
        if(i == 1) vis[0] = 1;
        for(ll j = 1; j <= m; j ++ ) {
            vis[j] = vis[j] + vis[j - 1];
        } 
        for(ll j = 1; j <= m; j ++ ) {
            if(g[i][j] == 1) {
                if(len[0] == -1) break;
                ll l = max(j - len[0], 1ll);
                ll r = j + len[0] + 1;
                a[i][l] += vis[j];
                if(r > l && r <= m) a[i][r] -= vis[j]; 
            }
        }
        for(ll j = 1; j <= m; j ++ ) {
            a[i][j] = (a[i][j] + a[i][j - 1]) % mod;
        }
        if(i > 1) {
            for(ll j = 1; j <= m; j ++ ) {
                a[i][j] -= vis[j];
            }
        }
        for(ll j = 1; j <= m; j ++ ) {
            if(g[i][j] == 1) {
                for(ll k = 1; k <= n - i; k ++ ) {
                    if(len[k] == -1) break;
                    ll l = max(j - len[k], 1ll);
                    ll r = j + len[k] + 1;
                    a[i + k][l] += a[i][j];
                    if(r > l && r <= m) a[i + k][r] -= a[i][j]; 
                }
            }
        }
    }
    for(ll i = 1; i <= m; i ++ ) {
        if(g[n][i] == 1) ans = (ans + a[n][i]) % mod;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1; cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}