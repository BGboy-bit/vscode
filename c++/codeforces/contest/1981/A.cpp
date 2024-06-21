#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> db2(61);

void Solve() {
    ll l, r; cin >> l >> r;
    for(ll i = 60; i >= 0; i -- ) {
        if(r >= db2[i]) {
            cout << i << "\n";
            return ;
        } 
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    db2[0] = 1;
    for(ll i = 1; i <= 60; i ++ ) {
        db2[i] = db2[i - 1] * 2;
    }
    ll T; cin >> T;
    while(T -- ) {
        Solve();
    }
}