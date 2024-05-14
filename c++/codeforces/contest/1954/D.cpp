#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
typedef array<ll, 2> PII; // vector<PII> a(n+1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 1e5 + 10;
bool multi = 0;

ll a[MAX];

ll dfs(ll cnt1, ll cnt2) {
    if(cnt1 == cnt2) return a[cnt1];
    else if(cnt2 - cnt1 == 1) return max(a[cnt1], a[cnt2]);
    
    ll mid = (cnt1 + cnt2) / 2;
    //right
    ll minn = inf;
    for(ll i = mid; i <= cnt2; i ++ ) minn = min(minn, a[i]);
    
}
void Solve() {
    ll n; cin >> n;
    ll kk = 0;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i]; kk = max(a[i], kk);
    }
    ll cnt1 = n;
    for(ll k = 1; k <= kk; k ++ ) {
        // ll cnt2 = cnt1;
        // cnt1 = (cnt2 + 1) / 2;
        // ll ans = inf;
        // ll maxx = 0;
        // while(cnt1 >= 1 && cnt2 >= 1) {
        //     for(ll i = cnt1; i <= cnt2; i ++ ) maxx = max(maxx, a[i]);
        //     ans = min(ans, (maxx + k - 1) / k);    
        // }
        // cout << ans << " ";
        dfs(1, n);
    }
    cout << "\n";
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