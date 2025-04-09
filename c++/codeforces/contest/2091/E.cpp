#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n; cin >> n;
    ll ans = 0;
    vector<ll> pri(n + 1);
    for(ll i = 2; i <= n; i ++ ) {
        if(!pri[i]) {
            pri[i] = 1;
            for(ll j = i; j <= n; j += i) {
                pri[j] = 1; ans ++ ;
            }
        }
    }
    cout << ans << "\n";
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