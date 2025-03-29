#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a;
    bool ff = 0;
    ll ans = k / 2 + 1;
    for(ll i = 1; i <= n; i ++ ) {
        ll x; cin >> x;
        if(n == k) {
            if(i % 2 == 0 && i / 2 != x && ans == k / 2 + 1) {
                ans = i / 2;
            }
        }
        else {
            if(i >= 2 && i <= n - k + 2) {
                if(x != 1) ff = 1;
            }
        }
    }
    if(n == k) {
        cout << ans << "\n"; return ;
    }
    if(ff) {
        cout << "1\n"; return ;
    }
    cout << "2\n"; return ;
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