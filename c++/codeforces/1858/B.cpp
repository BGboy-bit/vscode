#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 1e5 + 10;
bool multi = 1;//¶à×éÊäÈë

ll a[MAX], b[MAX], c[MAX];

void Solve() {
    ll n, m, d, ans = 0; 
    cin >> n >> m >> d;
    ll x; cin >> x; ll cnt = 0;
    if(x != 1) {a[++ cnt] = 1; a[++ cnt] = x;}
    else a[++ cnt] = 1;
    b[cnt] = a[cnt] - a[cnt - 1] - 1;
    c[cnt] = b[cnt] / d + 1; 
    ans = cnt - 1 + c[cnt];
    for(ll i = cnt + 1; i <= m + cnt - 1; i ++ ) {
        cin >> a[i];
        b[i] = a[i] - a[i - 1] - 1;
        c[i] = b[i] / d + 1;
        ans += c[i];
        c[i - 1] += b[i] / d;
    }
    a[m + cnt] = n;
    c[m + cnt - 1] += (n - a[m + cnt - 1]) / d;
    ans += (n - a[m + cnt - 1]) / d;
    ll minn = ans; ll summ = 0;
    for(ll i = cnt; i <= m + cnt - 1; i ++ ) {
        ll x;
        if(i + 1 == m + cnt) x = c[i] - ((n - a[i - 1]) / d);
        else if(a[i] == 1) x = 0;  
        else x = c[i] - ((a[i + 1] - a[i - 1] - 1) / d); 
        if(ans - x < minn) {minn = ans - x; summ = 1;}
        else if(ans - x == minn) summ ++ ;
    }
    cout << minn << " " << summ << "\n";
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