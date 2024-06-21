#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n; cin >> n;
    string s; cin >> s;
    s = '0' + s;
    bool ff = 0;
    bool ac = 0;
    for(ll i = 1; i <= n; i ++ ) {
        if(s[i] >= '0' && s[i] <= '9') {
            if(s[i] < s[i - 1] || ff) {
                ac = 1; break;
            }
        } else {
            ff = 1;
            if(s[i] < s[i - 1]) {
                ac = 1; break;
            }
        }
    }
    if(ac) {
        cout << "NO" << "\n";
    } else {
        cout << "YES" << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T; cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}