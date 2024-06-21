#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll h, n; cin >> h >> n;
    //h = 200000, n = 100;
    vector<ll> a(n + 1), c(n + 1);
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
        //a[i] = 200000;
    }
    for(ll i = 1; i <= n; i ++ ) {
        cin >> c[i];
        ///c[i] = 1;
    }
    ll l = 1, r = 1e12 + 10;
    while(l < r) {
        ll mid = l + r >> 1;
        ll m1 = mid - 1;
        ll sum = 0;
        for(ll i = 1; i <= n; i ++ ) {
            sum += a[i] * ((m1 + c[i] - m1 % c[i]) / c[i]); 
            if(sum >= h) {
                r = mid;
                break;
            }
        }
        if(r != mid) l = mid + 1;
    }
    cout << l << "\n";
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