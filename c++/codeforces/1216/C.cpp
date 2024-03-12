#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    vector<ll> v;
    ll n, m;
    cin >> n >> m;
    ll x = n / m;
    ll y = m % 10;
    ll z = y;
    ll sum = y;
    v.push_back(y);
    while(z) {
        z = (z + y) % 10;
        v.push_back(z);
        sum += z;
    }
    ll ans = 0;
    ll cnt = v.size();
    ans += sum * (x / cnt);
    for(ll i = 0; i < x % cnt; i ++ ) {
        ans += v[i];
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();
    int T = 1;
    cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}