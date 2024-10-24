#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const string ss = "!narek";

ll n, m; 

void AC(ll pos, ll &ed, ll &cnt, vector<string> &s) {
	for(ll i = 1; i <= m; i ++ ) {
		ll p = -1;
		for(ll j = 1; j <= 5; j ++ ) {
			if(ss[j] == s[pos][i]) {
				p = j; break;
			}
		}
		if(p == -1) continue;
		if(p == ed) {
			ed ++ ; cnt ++ ;
			if(ed == 6) ed = 1;
		} else {
			cnt -- ;
		}
	}
}

void Solve() {
	cin >> n >> m;
	vector<string> s(n + 1);
	for(ll i = 1; i <= n; i ++ ) {
		cin >> s[i]; s[i] = "!" + s[i];
	}
	vector<vector<ll>> dp(n + 1, vector<ll>(6, -1e6));
	dp[0][1] = 0; dp[1][1] = 0;
	for(ll i = 1; i <= n; i ++ ) {
		for(ll j = 1; j <= 5; j ++ ) {
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			ll ed = j, cnt = 0;
			AC(i, ed, cnt, s);
			dp[i][ed] = max(dp[i][ed], dp[i - 1][j] + cnt);
		}
	}
	ll ans = 0;
	for(ll i = 1; i <= 5; i ++ ) {
		ans = max(ans, dp[n][i] - (i - 1) * 2);
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	ll T; cin >> T;
	while(T -- ) {
		Solve();
	}
	return 0;
}