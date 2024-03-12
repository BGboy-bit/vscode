#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 1010;
bool multi = 1;//∂‡◊È ‰»Î

ll n, k;
ll a[MAX];

bool check(ll x) {
    for(ll i = 1; i <= n; i ++ ) {
        for(ll j = i, h = x, cnt = k; j <= n; j ++ , h -- ) {
            if(a[j] >= h) return true;
            else cnt -= h - a[j];
            if(cnt < 0) break;
        }
    }
    return false;
}

void Solve() {
    cin >> n >> k;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
    }
    ll l = 1, r = 1e8 + MAX;
    while(l < r) {
        ll mid = l + r + 1 >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << "\n";
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}