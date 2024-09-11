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
    ll n, k; cin >> n >> k;
    if(k == 0) {
        cout << 0 << "\n";
        return ;
    }
    ll ans = 0;
    if(k <= n) {
        cout << 1 << "\n";
        return ;
    } else {
        ans = 1;
        k -= n;
    }
    bool ff = 0;
    for(ll i = n - 1; i >= 1; ) {
        if(k > 0) {
            k -= i;
            ans ++ ;
            if(ff) {
                i -- ;
                ff = 0;
            }
            else ff = 1;
        }
        else break;
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