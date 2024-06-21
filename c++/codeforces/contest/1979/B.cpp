#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll x, y; cin >> x >> y;
    ll xx = 1 << 30;
    ll cnt = 0;
    while(xx >>= 1) {
        bool xf = false, yf = false; 
        if(x >= xx) {
            x -= xx; 
            xf = true;
        }
        if(y >= xx) {
            y -= xx;
            yf = true;
        }
        if(xf && yf || !xf && !yf) cnt ++ ;
        else cnt = 0;
    }
    cout << (1 << cnt) << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T; cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}