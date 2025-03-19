#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n, x; cin >> n >> x;
    if(x % 2 == 1) {
        for(ll i = 1; i <= n - 1; i ++ ) {
            cout << n << " ";
        }
        cout << n - 1 << "\n"; return ;
    } else {
        for(ll i = 1; i < n - 1; i ++ ) {
            cout << n - 1 << " ";
        }
        cout << n << " " << n - 1 << "\n"; return;
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