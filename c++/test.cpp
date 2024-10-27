#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
	int n, k;
	cin >> n >> k;

	string s;
	cin >> s;

	auto check = [&](string & s){
		int cnt = 0;
		for (int i = 0, cur = 0; i < n; ++i){
			if (s[i] == s[cur]){
				cnt ++;
				continue;
			}
			if (cnt < k){
				return i;
			}
			else if (cnt > k){
				return i - k;
			}
			else{
				cur = i;
				cnt = 1;
			}
		}
		return cnt > k ? n - k : n;
	};

	int p = check(s);
	if (p == n){
		cout << n << '\n';
		return;
	}

	reverse(s.begin(), s.begin() + p);
	rotate(s.begin(), s.begin() + p, s.end());

	int t = check(s);

	cout << (t == n ? p : -1) << '\n';
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