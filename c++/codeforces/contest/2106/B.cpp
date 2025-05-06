#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n, x; cin >> n >> x;
    for(ll i = 0; i < n; i ++ ) {
        if(i != x) {
            cout << i << " ";
        }
    }
    if(x < n) cout << x;
    cout << "\n";
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