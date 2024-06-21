#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// ll __gcd(ll a,ll b) {
//     return b > 0 ? __gcd(b, a % b) : a;
// }

void Solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n + 1), las(n + 1);
    ll res = -1;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
        if(res == -1) res = a[i];
        else res = __gcd(res, a[i]);
    }  
    for(ll i = n; i >= 1; i -- ) {
        if(i == n) las[i] = a[i];
        else las[i] = __gcd(las[i + 1], a[i]);
    }
    ll cnt, cntt, pre = 0;
    for(ll i = 1; i <= n; i ++ ) {
        if(i == 1) cntt = a[i];
        else cntt = __gcd(cntt, a[i]);
        if(cntt == res) {
            cnt = i;
            break;
        }
        pre = cntt;
    } 
    ll ans = res;
    for(ll i = cnt; i <= n; i ++ ) {
        //a[i] += k;
        if(i == cnt) res = a[i] + k;
        else res = __gcd(res, a[i] + k);
        if(i < n) ans = max(ans, __gcd(__gcd(pre, res), las[i + 1]));
        else ans = max(ans, __gcd(pre, res));
    }
    for(ll i = 1; i <= n; i ++ ) {
        if(i == 1) res = a[i] + k;
        else res = __gcd(res, a[i] + k);
        if(i < n)
            ans = max(ans, __gcd(res, las[i + 1]));
        else 
            ans = max(ans, res);
    }
    ans = max(ans, res);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll t; cin >> t;
    while(t -- ) {
        Solve();
    }
    return 0;
}
