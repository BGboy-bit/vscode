#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const long long inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 1e6 + 10;

ll fac[MAX],infac[MAX]; 
ll ksm(ll a ,ll k) //a代表底数，k代表大指数
{
    ll rec = 1;
    while(k)
    {
        if (k & 1)
            rec = rec * a % mod;
        k >>= 1;
        a = a * a % mod;
    }
    return rec;
}
//求排列组合 
inline ll C(ll a, ll b){
    return fac[a] * infac[a - b] % mod * infac[b] % mod;
}

ll n, m, a, b;

ll quick_mod(ll k, ll m, ll ans) {
    while(m) {
        if (m & 1) {
            ans = ans * k % mod;
        }
        m >>= 1;
        k = k * k % mod;
    }
    return ans;
}

void Solve() {
    ll ans = 0;
    cin >> n >> m >> a >> b;
    ll m1 = 0;
    ll a1 = 1;
    if(a < b) {
        for(ll i = 1; i <= n; i ++ ) {
            a1 = a * a1 % mod;
            ll b1 = quick_mod(b - a, n - i, a1);
            ll c1 = C(n, i) * b1 % mod;
            m1 = (m1 + quick_mod(i, m, 1)) % mod;
            ans = (ans + c1 * m1 % mod) % mod;
        }
        b = quick_mod(b, n, 1);
        ans = quick_mod(b, mod - 2, ans) % mod;
    }
    else {for(ll i = 1; i <= n; i ++ ) ans += quick_mod(i, m, 1);}
    cout << ans << "\n";
}


int main() {
    fac[0] = infac[0] = 1;
    for(ll i = 1; i< MAX; i ++ ){
        fac[i] = fac[i - 1] * i % mod;
        infac[i] = infac[i - 1] * ksm(i, mod - 2) % mod;
    }
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}