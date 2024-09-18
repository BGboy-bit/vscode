// 2024 ICPC网络赛第一场 
// G.the Median of the Median of the Median
// https://qoj.ac/contest/1794/problem/9314

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

bool check(ll x, vector<ll> &a) {
    vector<ll> sa(n + 1);
    vector<vector<ll>> b(n + 1, vector<ll>(n + 1)), sb(n + 1, vector<ll>(n + 1));
    for(ll i = 1; i <= n; i ++ ) {
        ll y = a[i] <= x ? 1 : -1;
        sa[i] = sa[i - 1] + y;
    }
    for(ll i = 1; i <= n; i ++ ) {
        for(ll j = i; j <= n; j ++ ) {
            b[i][j] = sa[j] - sa[i - 1] >= 0 ? 1 : -1;
        }
    }
    for(ll i = 1; i <= n; i ++ ) {
        for(ll j = 1; j <= n; j ++ ) {
            sb[i][j] = sb[i - 1][j] + sb[i][j - 1] - sb[i - 1][j - 1] + b[i][j];
        }
    }
    ll ans = 0;
    for(ll i = 1; i <= n; i ++ ) {
        for(ll j = i; j <= n; j ++ ) {
            ans += sb[j][j] - sb[i - 1][j] - sb[j][i - 1] + sb[i - 1][i - 1] >= 0 ? 1 : -1;
        }
    }
    return ans >= 0;
} 

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    vector<ll> a(n + 1), b(n + 1);
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i]; b[i] = a[i];
    }
    sort(b.begin() + 1, b.end());
    ll l = 1, r = n;
    while(l < r) {
        ll mid = l + r >> 1;
        if(check(b[mid], a)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << b[l] << '\n';
    return 0;
}