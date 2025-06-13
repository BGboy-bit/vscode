#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll len, n, m; cin >> len >> n >> m;
    if(n == 0) {
        cout << len << "\n"; return 0;
    }
    vector<ll> a(n + 2); 
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
    }
    a[0] = 0; a[n + 1] = len;
    ll l = 0, r = 1e10;
    while(l < r) {
        ll mid = l + r + 1 >> 1;
        ll cnt = 0;
        ll res = 0;
        for(ll i = 1; i <= n + 1; i ++ ) {
            if(a[i] - res < mid) {
                cnt ++ ; 
            } else {
                res = a[i];
            }
        }
        if(cnt <= m)
            l = mid; 
        else 
            r = mid - 1;
    }
    cout << l << "\n";
    return 0;
}