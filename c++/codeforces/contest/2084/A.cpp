#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n; cin >> n;
    if(n % 2 == 0) {
        cout << "-1\n"; return ;
    }
    cout << n << " ";
    for(ll i = 1; i <= n - 1; i ++ ) {
        cout << i << " \n"[i == n - 1];
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