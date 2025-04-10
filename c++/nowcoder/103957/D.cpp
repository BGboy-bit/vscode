#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    vector<ll> du(n + 1);
    for(ll i = 1; i < n; i ++ ) {
        ll x, y; cin >> x >> y;
        du[x] ++ ; du[y] ++ ;
    }
    if(n == 2) {
        cout << "1 1\n"; return 0;
    }
    ll maxx = 0, pos;
    for(ll i = 1; i <= n; i ++ ) {
        maxx = max(maxx, du[i]);
    }
    for(ll i = 1; i <= n; i ++ ) {
        if(du[i] < maxx) {
            pos = i;
            break;
        }
    }
    cout << maxx - 1 << " " << pos << "\n";
    return 0;
}