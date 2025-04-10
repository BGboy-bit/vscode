#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n, l, r; cin >> n >> l >> r;
    ll sum = 0;
    vector<ll> a, b, c;
    for(ll i = 1; i <= n; i ++ ) {
        ll x; cin >> x;
        if(i < l) b.push_back(x);
        else if(i >= l && i <= r) {
            a.push_back(x); sum += x;
        }
        else if(i > r) c.push_back(x);
    }
    sort(a.begin(), a.end()); sort(b.begin(), b.end()); sort(c.begin(), c.end());
    reverse(a.begin(), a.end());
    ll sumb = 0, sumc = 0;
    for(ll i = 0; i <= (r - l); i ++ ) {
        if(b.size() > i) {
            if(a[i] > b[i]) sumb += a[i] - b[i];
        }
        if(c.size() > i) {
            if(a[i] > c[i]) sumc += a[i] - c[i];
        }
    }
    cout << sum - max(sumb, sumc) << "\n"; 
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