#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 1;//¶à×éÊäÈë

ll a[MAX];

void Solve() {
    ll n; cin >> n;
    ll ans = 0;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i]; if(i == 1) ans += a[i] - 1;
        if(a[i] > a[i - 1] && i != 1) {
            ans += a[i] - a[i - 1];  
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