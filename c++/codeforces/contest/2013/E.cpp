#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n; cin >> n;
    vector<ll> a(n + 1);
    ll g = 0;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
        g = __gcd(g, a[i]);
    }
    for(ll i = 1; i <= n; i ++ ) {
        a[i] /= g;
    }
    ll cur = 0, ans = 0;
    for(ll i = 1; i <= n; i ++ ) {
        ll minn = 1e6;
        for(ll j = 1; j <= n; j ++ ) {
            minn = min(minn, __gcd(cur, a[j]));
        } 
        cur = minn;
        ans += cur;
        if(cur == 1) {
            ans += n - i;
            break;
        }
    }
    cout << ans * g << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T; cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}