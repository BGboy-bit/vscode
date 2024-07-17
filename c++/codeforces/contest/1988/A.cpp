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
bool multi = 1;

// ll dfs(ll x, ll k) {
//     if(x == 1) return 0;
//     if(x <= k) return 1;
//     ll ans = 1;
//     ll y = x / k;
//     ll z = x % k;
//     for(ll i = 1; i < k; i ++ ) {
//         ans += dfs(x / k, k);
//     }      
//     ans += dfs(x / k + z, k);
//     return ans;
// }

void Solve() {
    ll n, k; cin >> n >> k;
    ll ans = 0;
    while(n > 1) {
        if(n < k) {
            ans += 1;
            break;
        }
        ll x = n % k;
        ll y = n / k;
        ans += y;
        n = n / k + x;
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