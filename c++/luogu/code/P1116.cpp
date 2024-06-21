#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    vector<ll> a(n + 1);
    ll ans = 0;
    for(ll i = 1; i <= n; i ++ ) cin >> a[i];
    for(ll i = 1; i < n; i ++ ) {
        for(ll j = i + 1; j <= n; j ++ ) {
            if(a[i] > a[j]) {
                ll k = a[i];
                a[i] = a[j];
                a[j] = k;
                ans ++ ;
            }
        }
    }
    cout << ans << "\n";
}