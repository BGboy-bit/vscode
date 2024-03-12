#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N= 2e5 + 6;
ll a[N];
ll x[N], y[N], l[N];
void Solve() {
	ll n, m, a = 0, b = 0, t = 0;
	cin>> n >> m;
	while(n != m) {
		x[t] = a;
		y[t] = b;
		l[t ++ ] = min(n, m);
		if(n > m) {
			a += min(n, m);
			n -= min(n, m);
		} else {
			b += min(n, m);
			m -= min(n, m);
		}
	}
	x[t] = a;
	y[t] = b;
	l[t ++ ] = min(n, m);
	cout << "YES\n ";
	cout << t << '\n';
	for(ll i = 0; i < t; i ++ ){
		cout << x[i] << ' ' << y[i] << ' ' << l[i] << '\n';
	}
	
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
	ll T = 1;
	cin >> T;
	while(T--){
		Solve();
	}
}