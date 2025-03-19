#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n; cin >> n;
    vector<ll> a(2 * n + 1), b, c;
    ll sum1 = 0, sum2 = 0;
    for(ll i = 1; i <= n * 2; i ++ ) {
        cin >> a[i];
        sum1 += a[i];
    }
    sort(a.begin() + 1, a.end());
    for(ll i = 1; i < n; i ++ ) {
        sum2 += a[i];
        b.push_back(a[i]);
    } 
    sum2 *= 2;
    for(ll i = n; i <= 2 * n; i ++ ) {
        c.push_back(a[i]);
    }
    b.push_back(sum1 - sum2);
    for(ll i = 0; i < n; i ++ ) {
        cout << c[i] << " " << b[i] << " ";
    }
    cout << c[n] << "\n";
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