#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n; cin >> n;
    vector<ll> a(n + 2);
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
    }
    ll ans = 0;
    for(ll i = 1; i <= n; i ++ ) {
        if(a[i] > a[i - 1] && a[i] > a[i + 1]) {
            ans ++ ;
        } else if(a[i] > a[i - 1] && a[i] == a[i + 1]) {
            bool ff = 1;
            for(ll j = i + 1; j <= n; j ++ ) {
                if(a[j] > a[j + 1]) {
                    i = j; break;
                } else if(a[j] < a[j + 1]) {
                    i = j; ff = 0; break;
                }
            }
            if(ff) ans ++ ;
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