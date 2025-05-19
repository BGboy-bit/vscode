#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n; cin >> n;
    ll ans = 0;
    for(ll i = 1; i <= n; i ++ ) {
        ans += abs(n - i + 1 - i);
    }
    cout << ans / 2 + 1 << "\n";
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