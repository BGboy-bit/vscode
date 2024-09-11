// P1020 [NOIP1999 提高组] 导弹拦截
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> a;
ll n;

ll dp() {
    vector<ll> dp(n + 1);
    for(ll i = 1; i <= n; i ++ ) {
        dp[i] = 1;
        for(ll j = 1; j < i; j ++ ) {
            if(a[j] >= a[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    ll ans = -1;
    for(ll i = 1; i <= n; i ++ ) ans = max(ans, dp[i]);
    return ans; 
}

ll yxc() {
    vector<ll> q(n + 1);
    q[0] = -1;
    ll len = 0;
    for(ll i = 1; i <= n; i ++ ) {
        ll l = 0, r = len;
        while(l < r) {
            ll mid = l + r + 1 >> 1;
            if(q[mid] >= a[i]) l = mid;
            else r = mid - 1;
        }
        len = max(len, r + 1);
        q[r + 1] = a[i];
    }
    return len;
}

ll solve1() {
    vector<ll> b;
    for(ll i = 1; i <= n; i ++ ) {
        if(b.empty() || b.back() >= a[i]) b.push_back(a[i]);
        else *upper_bound(b.begin(), b.end(), a[i], greater<ll>()) = a[i];
    }
    return b.size();
}

ll solve2() {
    vector<ll> b;
    for(ll i = 1; i <= n; i ++ ) {
        if(b.empty() || b.back() < a[i]) b.push_back(a[i]);
        else *lower_bound(b.begin(), b.end(), a[i]) = a[i];
    }
    return b.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    a.push_back(0);
    ll x; while(cin >> x) a.push_back(x);
    n = a.size() - 1;
    // ll ans = dp();
    // ll ans = yxc();
    ll ans = solve1();
    ll ans1 = solve2();
    cout << ans << " " << ans1 << "\n";
    return 0;
}