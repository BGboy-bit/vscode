#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string s = "5 6 8 6 3 1 6 1 2 4 9 1 9 8 2 3 6 4 0 2 5 9 5 0 3 8 7 5 2 0 5 2 6 1 8 3 0 3 7 9 2 7 0 5 8 5 5 7 0 2 2 1 9 4 4 6 8 6 3 3 8 5 1 6 3 4 6 7 0 7 8 2 0 6 8 9 5 6 5 6 1 4 0 1 0 0 9 4 8 0 9 1 2 8 5 0 2 5 3 3";
vector<ll> a(101);

ll ans = 0;

void dfs(ll pos, ll nw, ll f, ll ff) {
	if(nw == 1) {       // 2
		for(ll i = pos + 1; i <= 100; i ++ ) {
			if(a[i] == 2) {
				dfs(i, nw + 1, 0, 0);
			}
		}
	} else if(nw == 2) { // 0
		for(ll i = pos + 1; i <= 100; i ++ ) {
			if(a[i] == 0) {
				dfs(i, nw + 1, 0, 0);
			}
		}
	} else if(nw == 3) { // 2
		for(ll i = pos + 1; i <= 100; i ++ ) {
			if(a[i] == 2) {
				dfs(i, nw + 1, 0, 0);
			}
		}
	} else if(nw == 4) { // 5
		for(ll i = pos + 1; i <= 100; i ++ ) {
			if(a[i] == 5) {
				dfs(i, nw + 1, 0, 0);
			}
		}
	} else if(nw == 5) {// 月1 
		for(ll i = pos + 1; i <= 100; i ++ ) {
			if(a[i] == 0) {
				dfs(i, nw + 1, 0, 0);
			} else if(a[i] == 1) {
				dfs(i, nw + 1, 1, 0);
			}
		}
	} else if(nw == 6) { // 月2 
		for(ll i = pos + 1; i <= 100; i ++ ) {
			if(f == 0) {
				if(a[i] <= 9 && a[i] >= 1) { // 1 - 9
					dfs(i, nw + 1, 0, a[i]);
				}
			} else if(f == 1) {
				if(a[i] <= 2 && a[i] >= 0) { // 11 - 12
					dfs(i, nw + 1, 1, a[i] + 10);
				}
			}
		}
	} else if(nw == 7) { // 日1 0/1/2/3
		for(ll i = pos + 1; i <= 100; i ++ ) {
			if(a[i] == 0) {
				dfs(i, nw + 1, 0, ff);
			} else if(a[i] == 1) {
				dfs(i, nw + 1, 1, ff);
			} else if(a[i] == 2) {
				dfs(i, nw + 1, 2, ff);
			} else if(a[i] == 3) {
				dfs(i, nw + 1, 3, ff);
			}
		}
	} else if(nw == 8) { // 日2 
		for(ll i = pos + 1; i <= 100; i ++ ) {
			if(ff % 2 == 1 && ff <= 7 || ff % 2 == 0 && ff <= 12 && ff >= 8) { // 31
				if(f == 0 && a[i] != 0 || f == 1 || f == 2 || f == 3 && (a[i] == 0 || a[i] == 1)) {
					ans ++ ;
				}
			} else if(ff == 2) { // 28
				if(f == 0 && a[i] != 0 || f == 1 || f == 2 && a[i] <= 8) {
					ans ++ ;
				}
			} else { // 30
				if(f == 0 && a[i] != 0 || f == 1 || f == 2 || f == 3 && a[i] == 0) {
					ans ++ ;
				}
			}
		}
	} 
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	for(ll i = 0; i < s.size(); i += 2) {
		a[i / 2 + 1] = s[i] - '0';
	}
	dfs(0, 1, 0, 0);
	cout << ans << "\n";
	return 0;
}