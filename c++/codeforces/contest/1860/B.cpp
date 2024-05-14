#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 1;//¶à×éÊäÈë

void Solve() {
    ll m, k, a1, a2;
    ll cnt = 0;
    cin >> m >> k >> a1 >> a2;
    if(a1 - m % k >= k) {
        m = m - m % k - k * ((a1 - m % k) / k);
    }
    else if(a1 >= m % k) {
        m = m - m % k;
    }
    else cnt += m % k - a1;
    cnt += max(m / k - a2, (ll)0);
    cout << cnt << "\n"; 
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