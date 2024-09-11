#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int MAX = 2e5  +10;
ll p[MAX];

void Solve() {
    ll n ;
    cin >> n;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> p[i];
    }
    for(ll i = 1; i <= n; i ++ ) {
        bool ff = 0;
        ll minn = n;
        ll res = i;
        for(ll j = 1; j <= minn; j ++ ) {
            if(i + j <= n) minn = min(minn, abs(p[i + j] - p[i]) + j);
            if(i - j >= 1) minn = min(minn, abs(p[i - j] - p[i]) + j);
        }
        cout << minn << " ";
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    // cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}