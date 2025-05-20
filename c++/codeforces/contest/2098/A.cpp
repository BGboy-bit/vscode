#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n; cin >> n;
    vector<ll> a(11);
    while(n != 0) {
        ll x = n % 10; a[x] ++ ;
        n /= 10;
    }
    for(ll i = 1; i <= 10; i ++ ) {
        for(ll j = 10 - i; j <= 9; j ++ ) {
            if(a[j] > 0) {
                cout << j; a[j] -- ; break;
            }
        }
    }
    cout << "\n";
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