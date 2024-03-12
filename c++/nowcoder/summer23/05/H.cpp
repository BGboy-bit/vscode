#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

//************����������***************
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 210;
bool multi = 0;
//***********************************


//**************ģ��******************

//���
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

//������
ll ksm(ll a ,ll k) {//a���������k�����ָ��
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

//���������
ll fac[MAX],infac[MAX]; 
void C_init() {
    fac[0] = infac[0] = 1;
    for(ll i = 1; i< MAX; i ++ ){
        fac[i] = fac[i - 1] * i % mod;
        infac[i] = infac[i - 1] * ksm(i, mod - 2) % mod;//����С���� x = a * ksm(b, mod - 2) % mod  {(a / b) % mod}
    }
}
inline ll C(ll a, ll b){
    return fac[a] * infac[a - b] % mod * infac[b] % mod;
}

//***********************************



//***********����������****************
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
    //Ԥ����0 - 200�����ı�����������[l, r] ���µ��������
    for(ll l = 1; l <= n; l ++ ) {
        for(ll r = l; r <= n; r ++ ) {
            for(ll i = 0; i <= 200; i ++ ) {
                beg[l][r][i] = beg[l][r - 1][i];
                if(i >= v[r]) beg[l][r][i] = max(beg[l][r - 1][i - v[r]] + w[r], beg[l][r - 1][i]);
            }
        } 
    }
    //����ÿ�����������ڵı���Ϊiǰһ������i - 1װ��l����Ʒ�������ڵı���װ����[l + 1,r]��i���������װ�����
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