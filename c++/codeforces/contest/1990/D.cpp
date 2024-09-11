#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
typedef array<ll, 2> PII; // vector<PII> a(n+1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 1;

void Solve() {
    ll n; cin >> n;
    ll ans = 0;
    ll ff = 0;
    for(ll i = 1; i <= n; i ++ ) {
        ll a; cin >> a;
        if(ff == 1) {
            a = max(0ll, a - 2);
        } else if(ff == 2 && a >= 3) {
            a = max(2ll, a - 2);
        }
        if(a == 0) {
            ff = 0;
            continue;
        }
        ans ++ ;
        if(a <= 2) {
            if(ff == 0 || ff == 2) {
                ff = 1;
            } else {
                ff = 2;
            }
        } else {
            ff = 0;
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