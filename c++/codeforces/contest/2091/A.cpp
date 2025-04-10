#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n; cin >> n;
    vector<ll> a(n + 1);
    ll ans = 0;
    map<ll, ll> mp;
    for(ll i = 1; i <= n; i ++ ) cin >> a[i];
    for(ll i = 1; i <= n; i ++ ) {
        mp[a[i]] ++ ;
        if(a[i] == 0) {
            if(mp[a[i]] <= 3) ans ++ ;
        } else if(a[i] == 2) {
            if(mp[a[i]] <= 2) ans ++ ;
        } else if(a[i] == 1 || a[i] == 3 || a[i] == 5) {
            if(mp[a[i]] <= 1) ans ++ ;
        }
        if(ans == 8) {
            cout << i << "\n"; return ;
        }
    }
    cout << "0\n";
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