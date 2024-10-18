#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 1e8 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    vector<ll> cat(3300);
    cat[0] = 1; cat[1] = 1;
    for(ll i = 2; i <= n; i ++ ) {
        for(ll j = 1; j <= i; j ++ ) {
            cat[i] += cat[j - 1] * cat[i - j];
            cat[i] %= mod;
        }
    }
    cout << cat[n] << '\n';
    return 0;   
}