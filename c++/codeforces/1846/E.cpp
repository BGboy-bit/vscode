#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;



void Solve() {
    ll n;
    cin >> n;
    bool ff = 0; 
    for(ll x = 2; x <= 1000; x ++ ) {
        ff = 0;
        for(ll m = 3; m <= 20; m ++ ) {
            ll ans = (pow(x, m) - 1) / (x - 1);
            if(ans == n) {
                ff = 1;
                break;
            }
            else if(ans > n) break;
        }
        if(ff) break;
    }
    if(ff) cout << "YES" << "\n";
    else cout << "NO" << "\n";
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