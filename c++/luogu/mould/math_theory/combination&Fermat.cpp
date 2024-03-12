//排列组合 / 费马小定理
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;

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
void C_init() {
    fac[0] = infac[0] = 1;
    for(ll i = 1; i< MAX; i ++ ){
        fac[i] = fac[i - 1] * i % mod;
        infac[i] = infac[i - 1] * ksm(i, mod - 2) % mod;//费马小定理 x = a * ksm(b, mod - 2) % mod  {(a / b) % mod}
    }
}

//求排列组合 
inline ll C(ll a, ll b){
    return fac[a] * infac[a - b] % mod * infac[b] % mod;
}

void Solve() {

}

int main() {
    C_init();
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}