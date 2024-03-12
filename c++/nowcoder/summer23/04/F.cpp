#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 1e6 + 10;

ll a[MAX];
unordered_map<ll, ll> mp;
void Solve() {
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
        mp[a[i]] = i;
    }
    sort(a + 1, a + n + 1);
    ll L = 1, R = n;
    for(ll i = 1; i < n; i ++ ) {
        // ll x = lower_bound(a + 1, a + n + 1, (a[L] + a[R] + 3) / 2) - a;//xÀë×ó±ßÔ¶
        ll mid = L + R >> 1;
        ll x = a[mid], l = a[L], r = a[R];
           if(x - l <= r - x) R -- ;
           else L ++ ;
    }
    cout << mp[a[L]] << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    // cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}