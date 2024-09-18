// D - Median Pyramid Hard
// https://atcoder.jp/contests/agc006/tasks/agc006_d

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1e5 + 10;
ll n;

bool check(ll x, vector<ll> &a) {
    vector<ll> c(2 * n);
    for(ll i = 1; i <= 2 * n - 1; i ++ ) {
        if(a[i] <= x)  
            c[i] = 1;
        else 
            c[i] = 0;
    }
    for(ll i = 0; i < n - 1; i ++ ) {
        if(c[n + i] == 0 && c[n + i + 1] == 0 || c[n - i] == 0 && c[n - i - 1] == 0) {
            return 0;
        } else if(c[n + i] == 1 && c[n + i + 1] == 1 || c[n - i] == 1 && c[n - i - 1] == 1) {
            return 1;
        }
    }
    return c[1];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    vector<ll> a(2 * n), b(2 * n);
    for(ll i = 1; i <= 2 * n - 1; i ++ ) {
        cin >> a[i]; b[i] = a[i];
    }
    sort(b.begin() + 1, b.end());
    ll l = 1, r = 2 * n - 1; 
    while(l < r) {
        ll mid = l + r >> 1;
        if(check(b[mid], a)) {
            r = mid;
        } else l = mid + 1;
    }
    cout << b[l] << "\n";
    return 0;
}