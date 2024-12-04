#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n; cin >> n;
    if(n == 1) {
        cout << "a\n"; return ;
    }
    for(ll i = 1; i <= n / 2; i ++ ) cout << "a";
    if(n % 2 == 0) 
        cout << "b";
    else 
        cout  << "bc";
    for(ll i = 1; i < n / 2; i ++ ) cout << "a";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T; cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}