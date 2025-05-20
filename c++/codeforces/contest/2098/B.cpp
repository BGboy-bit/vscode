#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n + 1);
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    ll l, r;
    if(k > 0) {
        if(n % 2 == 1) {
            l = max((n + 1) / 2 - (k - 1) / 2 - 1, 1ll);
            r = min((n + 1) / 2 + (k - 1) / 2 + 1, n);
        } else {
            l = max(n / 2 - k / 2, 1ll);
            r = min(n / 2 + k / 2 + 1, n); 
        }
    } else {
        l = (n + 1) / 2; r = (n + 2) / 2; 
    }
    cout << a[r] - a[l] + 1 << "\n";
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