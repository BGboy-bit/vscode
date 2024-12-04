#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

map<pair<ll, ll>, ll> sg;

void SG() {
	for(ll i = 1; i <= 100; i ++ ) {
		for(ll j = 1; j <= i; j ++ ) {
			set<ll> s;
			for(ll k = (i + 1) / 2; k < i; k ++ ) {
				s.insert(sg[{k, i - k}]);
			}
			for(ll k = (j + 1) / 2; k < j; k ++ ) {
				s.insert(sg[{k, j - k}]);
			}
			ll cnt = 0;
			while(s.find(cnt) != s.end()) {
				cnt ++ ;
			}
			sg[{i, j}] = cnt;
		}
	}
    cout << "  ";
    for(ll i = 1; i <= 9; i ++ ) {
        cout << i << " \n"[i == 9];
    }
    for(ll i = 1; i <= 9; i ++ ) {
        cout << i << " ";
        for(ll j = 1; j <= 9; j ++ ) {
            cout << sg[{max(j, i), min(j, i)}] << " \n"[j == 9];
        }
    }
}

void Solve() {
	ll n; cin >> n;
	vector<ll> a(n + 1);
	for(ll i = 1; i <= n; i ++ ) {
		cin >> a[i];
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	SG();
	ll T = 1; cin >> T;
	while(T -- ) {
		// Solve();
	}
	return 0;
}
