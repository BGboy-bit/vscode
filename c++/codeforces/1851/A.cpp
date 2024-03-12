#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;

ll n, m, k, H, h;

void Solve() {
    ll ans = 0;
    cin >> n >> m >> k >> H; 
    for(ll i = 1; i <= n; i ++ ) {
        cin >> h;
        if(abs(H - h) % k == 0 && abs(H - h) / k > 0 && abs(H - h) / k < m) ans ++ ;
    }
    cout << ans << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}