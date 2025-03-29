#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n, m; cin >> n >> m;
    vector<ll> a(n + 1), r(n + 1);
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
    }
    ll maxx = 0;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> r[i]; maxx = max(maxx, r[i]);
    }
    
    vector<vector<pair<ll, ll>>> ans(maxx + 1);
    for(ll i = 1; i <= n; i ++ ) {
        ll x = a[i], y = r[i];
        for(ll j = 0; j <= y; j ++ ) {
            ll l = 0, r = y; 
            while(l < r) {
                ll mid = l + r + 1 >> 1;
                if(mid * mid + j * j > y * y) {
                    r = mid - 1;
                } else {
                    l = mid;
                }
            }
            ans[j].push_back({x - l, x + l});
        }
    }
    ll sum = 0;
    for(ll i = 0; i <= maxx; i ++ ) {
        ll sum1 = 0;
        sort(ans[i].begin(), ans[i].end());
        ll l1 = -1e13, r1 = -1e13;
        for(auto [l, r] : ans[i]) {
            if(r1 < l) {
                l1 = l, r1 = r;
                sum1 += r - l + 1;
            } else {
                sum1 += max(0ll, r - r1);
                r1 = max(r, r1);
            }
        }
        if(i > 0) sum1 *= 2;
        sum += sum1; 
    }
    cout << sum << "\n";
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