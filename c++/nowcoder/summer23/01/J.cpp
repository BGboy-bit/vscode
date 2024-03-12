#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int inf = 0x3f3f3f3f;
const int MAX = 2e5 + 10;
ll mod = 998244353;

ll a[41];
ll n, m;
ll x = 1, y = 1;

ll Prime(ll n, ll cnt) {
    ll ans = 1; 
    while(cnt) {
        if (cnt & 1) {
            ans = ans * n % mod;
        }
        cnt >>= 1;
        n = n * n % mod;
    }
    return ans;
}


void Solve() {
    cin >> n >> m;
    ll xl = 0, xr = 0;
    for(ll i = 1; i <= 40; i ++ ) {
        if(n < a[i] - 1 && xl == 0) xl = i - 1;
        if(n + m - 1 < a[i] - 1 && xr == 0) xr = i - 1;
    }
    if(xl == xr) {
        x = x * Prime(a[xl] - 1, m) % mod;
        y = y * Prime(a[xl], m) % mod;
    }
    else {
        x = x * Prime(a[xl] - 1, a[xl + 1] - 1 - n) % mod;
        y = y * Prime(a[xl], a[xl + 1] - 1 - n) % mod;

        x = x * Prime(a[xr] - 1, n + m - a[xr] + 1) % mod;
        y = y * Prime(a[xr], n + m - a[xr] + 1) % mod;

        for(ll i = xl + 1; i < xr; i ++ ) {
            x = x * Prime(a[i] - 1, a[i + 1] - a[i]) % mod;
            y = y * Prime(a[i], a[i + 1] - a[i]) % mod;
        }
    }
    
    ll ans = x * Prime(y, mod - 2) % mod;
    cout << ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    // cin >> T;
    a[0] = 1;
    for(ll i = 1; i <= 40; i ++ ) {
        a[i] = a[i - 1] * 2;
    }
    while(T --) {
        Solve();
    }
    return 0;
}