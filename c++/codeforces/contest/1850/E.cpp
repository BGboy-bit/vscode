#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef unsigned long long ll;
typedef double db;

const db PI=acos(-1);
const ll inf = 1e10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 1;//∂‡◊È ‰»Î

ll s[MAX], n, c; 

bool check(ll w) {
    ll sum = 0;
    for(ll i = 1; i <= n; i ++ ) {
        sum += (s[i] + 2 * w) * (s[i] + 2 * w);
        if(sum > c) return false;
    }
    return true;
}

ll bin_bearch(ll l, ll r) {
    while(l < r) {
        ll mid = l + r + 1 >> 1;
        if(check(mid)) {
            l = mid;
        }
        else r = mid - 1;
    }
    return l;
}

void Solve() {
    cin >> n >> c;
    for(ll i = 1; i <= n; i ++ ) cin >> s[i];
    cout << bin_bearch(1, inf) << "\n";
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}