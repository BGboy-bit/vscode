#include<bits/stdc++.h>
using namespace std;
typedef long long i128;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 1e9 + 7;
const int MAX = 5e5 + 10;
bool multi = 0;//多组输入

ll p2[MAX];
vector<ll> l[MAX], r[MAX];
ll res[MAX];

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
//***********************************

void Solve() {
    p2[0] = 1;
    for(ll i = 1; i < MAX; i ++ ) {p2[i] = p2[i - 1] * 2 % mod;}   
     ll n; n = read();
    for(ll i = 1; i <= n; i ++ ) {
        ll l1, r1, l2, r2;
        // cin >> l1 >> r1 >> l2 >> r2;
        l1 = read(); r1 = read(); l2 = read(); r2 = read();
        l[l1].push_back(i); l[l2].push_back(i);
        r[r1].push_back(i); r[r2].push_back(i);
    }
    ll ans = 0, summ = 0, xx = 0;
    for(ll i = 1; i <= MAX; i ++ ) {
        for(auto j : l[i]) {
            res[j] ++ ;
            if(res[j] == 1) summ ++ ;
            if(summ == n) ans = (ans + p2[xx]) % mod;
            if(res[j] == 2) xx ++ ; 
        }
        for(auto j : r[i]) {
            res[j] -- ;
            if(res[j] == 0) summ -- ;
            if(res[j] == 1) xx -- ;
        }
    }
    cout << ans << "\n";
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) T = read();
    while(T --) {
        Solve();
    }
    return 0;
}