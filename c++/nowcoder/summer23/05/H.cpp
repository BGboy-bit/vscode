#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

//************常量定义区***************
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 210;
bool multi = 0;
//***********************************


//**************模板******************

//快读
inline i128 read(){
    i128 x = 0, f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9'){
        if(ch == '-')
            f = -1;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9'){
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
inline void print(i128 x){
    if(x < 0){
        putchar('-');
        x = -x;
    }
    if(x > 9)
        print(x / 10);
    putchar(x % 10 + '0');
}

//快速幂
ll ksm(ll a ,ll k) {//a代表底数，k代表大指数
    a %= mod;
    ll rec = 1;
    while(k) {
        if (k & 1)
            rec = rec * a % mod;
        k >>= 1;
        a = a * a % mod;
    }
    return rec;
}

//求排列组合
ll fac[MAX],infac[MAX]; 
void C_init() {
    fac[0] = infac[0] = 1;
    for(ll i = 1; i< MAX; i ++ ){
        fac[i] = fac[i - 1] * i % mod;
        infac[i] = infac[i - 1] * ksm(i, mod - 2) % mod;//费马小定理 x = a * ksm(b, mod - 2) % mod  {(a / b) % mod}
    }
}
inline ll C(ll a, ll b){
    return fac[a] * infac[a - b] % mod * infac[b] % mod;
}

//***********************************



//***********变量定义区****************
ll n, m;
ll w[MAX], v[MAX];
ll siz[MAX];
ll beg[MAX][MAX][MAX];
ll dp[MAX][MAX];
//***********************************


void Solve() {
    cin >> n >> m;
    for(ll i = 1; i <= n; i ++ ) cin >> v[i] >> w[i];
    if(m > n) {
        for(ll i = 1; i <= m - n; i ++ ) cin >> siz[1];
    } 
    m = min(m, n);
    for(ll i = 1; i <= m; i ++ ) cin >> siz[i];
    //预处理0 - 200容量的背包能在区间[l, r] 放下的最大质量
    for(ll l = 1; l <= n; l ++ ) {
        for(ll r = l; r <= n; r ++ ) {
            for(ll i = 0; i <= 200; i ++ ) {
                beg[l][r][i] = beg[l][r - 1][i];
                if(i >= v[r]) beg[l][r][i] = max(beg[l][r - 1][i - v[r]] + w[r], beg[l][r - 1][i]);
            }
        } 
    }
    //遍历每个背包，现在的背包为i前一个背包i - 1装了l件物品加上现在的背包装下了[l + 1,r]中i背包最多能装的体积
    ll ans = 0;
    for(ll i = 1; i <= m; i ++ ) {
        for(ll r = 1; r <= n; r ++ ) {
            for(ll l = 0; l < r; l ++ ) {
                dp[r][i] = max(dp[r][i], dp[l][i - 1] + beg[l + 1][r][siz[i]]);
                ans = max(ans, dp[r][i]);
            }
        }
    }
    cout << ans << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}