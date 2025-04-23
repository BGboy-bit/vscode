#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n, k; cin >> n >> k;
    vector<ll> l(n + 1), r(n + 1);
    for(ll i = 1; i <= n; i ++ ) {
        cin >> l[i];
    }
    for(ll i = 1; i <= n; i ++ ) {
        cin >> r[i];        
    }
    ll ans = 0;
    priority_queue<ll> a;
    for(ll i = 1; i <= n; i ++ ) {
        ans += max(l[i], r[i]);
        a.push(min(l[i], r[i]));
    }
    k -- ;
    while(k -- ) {
        ans += a.top(); a.pop();
    }
    cout << ans + 1 << "\n";
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