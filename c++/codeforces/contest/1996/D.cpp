#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
typedef array<ll, 2> PII; // vector<PII> a(n + 1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int maxn = 1e6 + 10;
bool multi = 1;

void Solve() {
    ll n, x; cin >> n >> x;
    ll ans = 0;
    for(ll i = 1;i <= x / i; i ++ ) {
        ll n1 = i * i + i * i + i * i;
        ll x1 = i * 3;
        if(n1 > n || x1 > x) break;
        for(ll j = i;; j ++ ) {
            ll n2 = i * j + j * i + j * j;
            ll x2 = i + j * 2;
            if(n2 > n || x2 > x) break;            
            for(ll k = j;; k ++ ) {
                ll n3 = i * j + j * k + i * k;
                ll x3 = i + j + k;
                if(n3 <= n && x3 <= x) {
                    if(i == j && i == k) ans ++ ;
                    else if(i != j && j == k || i == j && j != k) ans += 2;
                    else ans += 3;
                } else break;
            }
        }
    }
    cout << ans << "\n";
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}