// Monotonic Subsequence
// http://10.21.15.91/contest/1070/problem/F

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    ll T = 1; cin >> T;
    while(T -- ) {
        ll n; cin >> n;
        ll o = ceil(sqrt(n));
        ll m = ceil(1.0 * n / o);
        ll p = n;
        for(ll i = 1; i <= o; i ++ ) {
            if(p > m) {
                for(ll j = i * m; j > (i - 1) * m; j -- ) {
                    cout << j << " ";
                }
                p -= m;
            } else {
                for(ll j = n; p > 0; j --, p -- ) {
                    cout << j << " \n"[p == 1];
                }
            }
        }
    }
    return 0;
}