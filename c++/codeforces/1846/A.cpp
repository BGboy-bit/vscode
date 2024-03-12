#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;



void Solve() {
    ll n, a, b, ans = 0;
    cin >> n;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a >> b;
        if(a > b) ans ++ ;
    }
    cout << ans << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}