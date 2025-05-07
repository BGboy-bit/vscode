#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n; cin >> n;
    string s; cin >> s;
    ll ans = 0;
    for(ll i = 0; i < n; i ++ ) {
        if(s[i] == '1') {
            ans += n - 1;
        } else {
            ans ++ ;
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