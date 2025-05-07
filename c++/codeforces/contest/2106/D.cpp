#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n, m; cin >> n >> m;
    vector<ll> a(n + 1), b(m + 1);
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
    }
    for(ll i = 1; i <= m; i ++ ) {
        cin >> b[i];
    }
    vector<ll> pre(m + 1, n + 1), aft(m + 1);
    ll pos1 = 1, pos2 = m;
    for(ll i = 1; i <= n; i ++ ) {
        if(a[i] >= b[pos1]) {
            pre[pos1] = i; pos1 ++ ;
            if(pos1 == m + 1) {
                cout << "0\n"; return ;
            }
        }
    }
    for(ll i = n; i >= 1; i -- ) {
        if(a[i] >= b[pos2]) {
            aft[pos2] = i; pos2 -- ;
            if(pos2 == 0) {
                cout << "0\n"; return ;
            }
        }
    }
    ll ans = 2e9 + 10;
    if(pos2 == 1) {
        ans = min(ans, b[1]);
    }
    for(ll i = 1; i <= m - 2; i ++ ) {
        if(pre[i] < aft[i + 2]) {
            ans = min(ans, b[i + 1]);
        }
    }
    if(pos1 == m) {
        ans = min(ans, b[m]);
    }
    ans = ans > 1e9 ? -1 : ans;
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