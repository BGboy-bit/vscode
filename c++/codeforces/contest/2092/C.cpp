#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n; cin >> n;
    vector<ll> a, b;
    ll maxx = 0, sum = 0;
    for(ll i = 1; i <= n; i ++ ) {
        ll x; cin >> x;
        if(x % 2) a.push_back(x);
        else b.push_back(x);
        maxx = max(maxx, x);
        sum += x;
    }
    if(b.size() == 0 || a.size() == 0) {
        cout << maxx << "\n"; return ;
    } else {
        cout << sum - a.size() + 1 << "\n";
    }
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