#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 1000;
bool multi = 1;//¶à×éÊäÈë

void Solve() {
    ll n;
    cin >> n;
    ll ans = 0;
    for(ll i = 1; i <= n; i ++ ) {
        ll summ = 0; ll maxx = 0;
        for(ll k = 1; k < i; k ++ ) {
            summ += k * k; 
            maxx = max(k * k, maxx);           
        }
        for(ll k = i; k <= n; k ++ ) {
            summ += k * (n + i - k);
            maxx = max(k * (n + i - k), maxx);
        }
        summ -= maxx;
        ans = max(summ, ans);
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