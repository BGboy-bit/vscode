#include<bits/stdc++.h>
using namespace std;
// typedef __int128 i128;
typedef long long ll;
typedef long long i128;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 1e6 + 10;
bool multi = 0;//∂‡◊È ‰»Î

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

ll n;
// ll a[MAX];
ll pos[MAX];
ll s[MAX];
vector<bool> ff(MAX);
void Solve() {
    n = read();
    ll a;
    ll cnt = 0, ans = 0, res = 1;
    ll cnt1 = 0, summ = 0, dot = 1;
    for(ll i = 1; i <= n; i ++ ) {
        a = read();
        if(a == 1) {
            s[++ cnt] = a; pos[cnt] = i;
            cnt1 ++ ; summ += cnt1;
        }
        else {
            if(res < a - 1) {ans += summ; summ = 0; cnt1 = 0; dot = cnt + 1; res = 1; continue;}
            for(ll j = cnt; j >= dot; j -- ) {
                if(s[j] == a - 1) {
                    s[j] = a; 
                    res = max(res, a); summ += cnt1;
                    break;
                }
                else {
                    if(!ff[j]) {ans += i - pos[j]; ff[j] = 1; summ -= i - pos[j]; cnt1 -- ;}
                }
            }
        }
    }
    for(ll i = dot; i <= cnt; i ++ ) {
        if(!ff[i]) ans += n - pos[i] + 1;
    }
    // cout << ans << "\n";
    print(ans);
    printf("\n");
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}
