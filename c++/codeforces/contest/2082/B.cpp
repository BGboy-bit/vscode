#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll x, n, m; cin >> x >> n >> m;
    ll cnt = 0;
    ll ans1 = x, ans2 = x;
    for(ll n1 = n, m1 = m; n1 + m1 > 0; ) {
        if(m1 > 0 && ans1 > 1) {
            ans1 = ans1 + 1 >> 1; m1 -- ;
        }
        else if(n1 > 0 && ans1 > 0) {
            ans1 /= 2; n1 -- ;
        }
        else if(ans1 <= 1) break;
    }
    for(ll n2 = n, m2 = m; n2 + m2 > 0; ) {
        if(n2 > 0 && ans2 > 0) {
            ans2 /= 2; n2 -- ;
        }   
        else if(m2 > 0 && ans2 > 1) {
            ans2 = ans2 + 1 >> 1; m2 -- ;
        }
        else if(ans2 <= 1) break;
    }
    cout << ans1 << " " << ans2 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1; cin >> T;
    while(T -- ) {
        Solve();
    } 
    return 0;
}