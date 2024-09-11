#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
typedef array<ll, 2> PII; // vector<PII> a(n+1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 1;

ll ac(ll res1, ll res2, ll cnt1, ll cnt2, ll m) {
    ll cnt = min(m / res1, cnt1);
    ll ans = cnt * res1;
    if(cnt2 == 0) return ans;
	ll cntt = min((m - ans) / res2, cnt2);
	ll sum = cntt * res2;
	ll cnttt = min(cnt, cnt2 - cntt);
	ans = min(ans + sum + cnttt, m);
    return ans;
}

void Solve() {
    ll n, m; cin >> n >> m;
    vector<ll> a(n + 1);
    for(ll i = 1; i <= n; i ++ ) cin >> a[i];
    map<ll, ll> mp;
    ll ans = 0;
	ll x;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> x;
        mp[a[i]] = x;
    }
    sort(a.begin() + 1, a.end());
	ll res1, res2, cnt1, cnt2, cnt, sum1, sum2, cntt, cnttt; 
    for(ll i = 1; i <= n; i ++ ) {
        res1 = a[i], res2 = a[i] + 1, cnt1 = mp[res1], cnt2 = 0;
		if(a[i + 1] == res2) cnt2 = mp[res2];
        // ans = max(ans, ac(res, res + 1, cnt1, cnt2, m));
		cnt = min(m / res1, cnt1);
		sum1 = cnt * res1;
		cntt = min((m - sum1) / res2, cnt2);
		sum2 = cntt * res2;
		cnttt = min(cnt, cnt2 - cntt);
		ans = max(ans, min(sum1 + sum2 + cnttt, m));
	}
	cout << ans << "\n";
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