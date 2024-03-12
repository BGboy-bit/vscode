#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 1e9 + 7;
const int MAX = 1e6 + 10;
bool multi = 0;//多组输入

ll a[MAX];
ll ff[MAX], fff[MAX];
ll l[MAX], r[MAX], l1[MAX], r1[MAX];
ll L[MAX], R[MAX];
ll b[MAX], c[MAX];

ll ksm(ll a ,ll k) {//a代表底数，k代表大指数
    ll rec = 1;
    while(k) {
        if (k & 1)
            rec = rec * a % mod;
        k >>= 1;
        a = a * a % mod;
    }
    return rec;
}
void Solve() {
    ll n;
    cin >> n;
    ll maxx = 0;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> l[i] >> r[i] >> l1[i] >> r1[i];
        a[l[i]] ++ ; a[r[i] + 1] -- ; a[l1[i]] ++ ; a[r1[i] + 1] -- ;
        ll l2 = max(l[i], l1[i]); ll r2 = min(r[i], r1[i]);
        L[i] = l2; R[i] = r2;
        if(l2 <= r2) {a[l2] -- ; a[r2 + 1] ++ ; }
        maxx = max(maxx , max(r[i], r1[i]));
    }
    bool f = 0;
    for(ll i = 1; i <= maxx; i ++ ) {
        a[i] = a[i - 1] + a[i];
        if(a[i] == n) {ff[i] = 1; f = 1; }
        b[i] = ff[i] + b[i - 1];
    }
    if(!f) {cout << "0" << "\n"; return ; }
    ll ans = 0;
    ll L1 = 0, R1 = inf; 
    for(ll i = 1; i <= n; i ++ ) {
        ll l2 = L[i], r2 = R[i];
        if(l2 <= r2) {
            if(b[r2] - b[l2 - 1] > 0) {
                ans ++ ;
                L1 = max(L1, l2); R1 = min(R1, r2);
            }
        }
    }

    if(L1 != 0) {//存在重边的组
        for(ll i = L1; i <= R1; i ++ ) {
            if(a[i] == n) fff[i] = 1;
            c[i] = fff[i] + c[i - 1];
        }
        for(ll i = 1; i <= maxx; i ++ ) {
            c[i] = c[i - 1] + c[i];
        }
        bool ac = 1, ffff = 0;
        for(ll i = 1; i <= n; i ++ ) {
            ll l2 = L[i], r2 = R[i];
            if(r2 < l2) {
                if(c[r[i]] - c[l[i] - 1] > 0 && c[r1[i]] - c[l1[i] - 1] > 0) {
                    ffff = 1;//存在没有重边的组
                }
                else {
                    ac = 0; break;
                }
            }
        }
        if(ac && ffff) ans ++ ;
    }

    else {//不存在重边的组··
        bool ac = 1;
        for(ll i = 1; i <= n; i ++ ) {
            if(b[r[i]] - b[l[i] - 1] == 0 || b[r1[i]] - b[l1[i] - 1] == 0) {
               ac = 0; break;
            }
        }
        if(ac) ans ++ ;
    }

    cout << ksm(2, ans) << "\n";
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