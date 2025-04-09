#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n; cin >> n;
    vector<ll> a(n + 1), b;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    for(ll i = 2; i <= n; i ++ ) {
        if(a[i] % a[1] == 0) {
            b.push_back(a[i]);
        }
    }
    if(b.size() == 0) {
        cout << "No\n"; return ;
    }
    ll ans = b[0];
    for(auto x : b) {
        ans = gcd(x, ans);
    }
    if(ans == a[1]) {
        cout << "Yes\n"; 
    } else {
        cout << "No\n";
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