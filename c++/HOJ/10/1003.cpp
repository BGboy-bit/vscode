#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 1e9 + 7;
const int MAX = 2e5 + 10;
bool multi = 1;//¶à×éÊäÈë

void Solve() {
    ll n, k;
    cin >> n >> k;
    ll ans = 1;
    for(ll i = 1; i <= n; i ++ ) {
        ans = ans * i % mod; 
    }
    for(ll i = 3; i <= n; i ++ ) {
        ans = ans * min(k, i - 1) % mod;
    }
    cout << ans << "\n";
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