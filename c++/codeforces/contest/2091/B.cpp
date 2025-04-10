#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n, x; cin >> n >> x;
    vector<ll> a(n + 1);
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    reverse(a.begin() + 1, a.end());
    ll res = a[1], cur = 1;
    ll ans = 0;
    for(ll i = 1; i <= n; i ++ ) {
        if(res * (i - cur + 1) >= x) {
            ans ++ ; 
            if(i < n) cur = i + 1;
        } 
        if(i < n) res = a[i + 1];
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