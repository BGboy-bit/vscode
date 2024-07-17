// P1351 [NOIP2014 提高组] 联合权值
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 200100;
const int mod = 10007;
vector<ll> g[N];
ll w[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    for(ll i = 1; i < n; i ++ ) {
        ll u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(ll i = 1; i <= n; i ++ ) {
        cin >> w[i];
    }
    ll ans1 = 0, ans2 = 0;
    for(ll u = 1; u <= n; u ++ ) {
        ll max1 = 0, max2 = 0, sum = 0; 
        for(ll v : g[u]) {
            if(w[v] > max1) {
                max2 = max1; max1 = w[v];
            } else if(w[v] > max2) {
                max2 = w[v];
            }
            ans2 = (ans2 + sum * w[v]) % mod;
            sum = (sum + w[v]) % mod;
        }
        ans1 = max(ans1, max1 * max2);
    } 
    cout << ans1 << " " << (ans2 * 2) % mod << "\n";
    return 0;
}