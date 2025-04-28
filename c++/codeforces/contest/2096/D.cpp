#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n; cin >> n;
    map<ll, ll> mp1, mp2;
    for(ll i = 1; i <= n; i ++ ) {
        ll x, y; cin >> x >> y;
        mp1[x] ++ ;
        mp2[x + y] ++ ;
    }
    ll ax, ay;
    for(auto [x, cnt] : mp1) {
        if(cnt % 2 == 1) {
            ax = x; break;
        }
    }
    for(auto [xy, cnt] : mp2) {
        if(cnt % 2 == 1) {
            ay = xy - ax; break;
        }
    }    
    cout << ax << " " << ay << "\n";
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