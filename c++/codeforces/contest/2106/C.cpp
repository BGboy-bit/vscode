#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n + 1), b(n + 1);
    ll mx = 0, mn = 1e9 + 10;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
        mx = max(mx, a[i]); mn = min(mn, a[i]);
    }
    ll res = -1;
    bool ff = 1;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> b[i];
        if(b[i] != -1) {
            if(res == -1) {
                res = b[i] + a[i];
            } else {
                if(res != b[i] + a[i]) {
                    ff = 0;
                }
            }
        } 
    }
    if(!ff) {
        cout << "0\n"; return ;
    }
    if(res == -1) {
        cout << max(0ll, k - (mx - mn) + 1) << "\n"; return ;
    } 
    for(ll i = 1; i <= n; i ++ ) {
        if(b[i] == -1) {
            if(res - a[i] > k || res - a[i] < 0) {
                cout << "0\n"; return ;
            }
        }
    }
    cout << "1\n";
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