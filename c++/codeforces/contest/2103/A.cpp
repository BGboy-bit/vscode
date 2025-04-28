#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n; cin >> n;
    vector<ll> a(n + 1);
    ll ans = 0;
    for(ll i = 1; i <= n; i ++ ) {
        ll x; cin >> x;
        a[x] ++ ;
        if(a[x] == 1) {
            ans ++ ;
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