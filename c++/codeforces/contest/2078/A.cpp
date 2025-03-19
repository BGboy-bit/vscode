#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n, x; cin >> n >> x;
    vector<ll> a(n + 1);
    ll sum = 0;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
        sum += a[i];
    }
    if(x * n != sum) {
        cout << "No\n"; return ;
    } else {
        cout << "Yes\n"; return ;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cin.tie(0);
    ll T = 1; cin >> T;
    while(T -- ) {
        Solve();
    } 
    return 0;
}