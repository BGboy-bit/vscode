#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 1;//∂‡◊È ‰»Î

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

ll nin[20];
ll n;
void Solve() {
    i128 ans = 0;
    n = read();
    for(ll i = 1; i <= 10; i ++ ) {
        if(nin[i] < n) ans +=  i * (nin[i] - nin[i - 1]);
        else {
            ans += i * (n - nin[i - 1]);
            break;
        }
    }
    print(ans);
    printf("\n");
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    nin[0] = 0;
    for(ll i = 1; i <= 10; i ++ ) nin[i] = nin[i - 1] * 10 + 9;
    ll T = 1;
    if(multi) T = read();
    while(T --) {
        Solve();
    }
    return 0;
}