#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll x; cin >> x;
    ll y = 0;
    bool ff = 1;
    for(ll i = 0; (1 << i) <= x; i ++ ) {
        ll z = x & (1 << i);
        if(z == 0) {
            y += (1 << i);
        } else if(ff) {
            ff = 0; y += (1 << i);
        }
    }
    if((x ^ y) + y <= x || y >= x) {
        cout << "-1\n"; return ;
    } else {
        cout << y << "\n";
    }
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