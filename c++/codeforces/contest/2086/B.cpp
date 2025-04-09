#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n, k, x; cin >> n >> k >> x;
    vector<ll> a(n + 1);
    ll sum = 0;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
        sum += a[i];
    }
    ll ans = x / sum;
    ll y = x % sum;
    if(ans + (y == 0 ? 0 : 1) > k) {
        cout << "0\n"; return ;
    }
    ll pos = n + 1;
    while(y > 0) {
        y -= a[ -- pos];
    }
    cout << n * k - ans * n - n + pos << "\n";
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