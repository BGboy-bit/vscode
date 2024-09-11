#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 1e9 + 7;
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


ll n, m;
ll deg[MAX];
ll cnt[MAX];

void Solve() {
    cin >> n >> m;
    vector<ll> deg(n + 1, 0);
    vector<ll> cnt(n, 0);
    for(ll i = 1; i <= m; i ++ ) {
        ll u, v;
        cin >> u >> v;
        deg[u] ++ ; deg[v] ++ ;
    }
    ll ans = 0;
    for(ll i = 1; i <= n; i ++ ) {
        for(ll j = 2; j <= deg[i]; j ++ ) {
            cnt[j] = (cnt[j] + C(deg[i], j)) % mod;
        }
    }
    for(ll i = 2; i < n; i ++ ) {
        ans = ans ^ cnt[i];
    }
    cout << ans << '\n';
}

int main() {
    fac[0] = infac[0] = 1;
    for(ll i = 1; i < MAX; i ++ ){
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