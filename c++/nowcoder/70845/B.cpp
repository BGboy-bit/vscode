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

db a[MAX];

void Solve() {  
    db sum = 0;
    ll n;
    db x, y; 
    cin >> n >> x >> y;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i]; sum += a[i];
    }
    sort(a + 1, a + n + 1);
    sum -= max(a[n] * (100 - x) / 100 + min(y, a[n - 1]), min(a[n], y) + a[n - 1] * (100 - x) / 100);
    cout << sum << "\n";
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