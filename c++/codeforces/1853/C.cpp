#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;

ll n , k;
ll a[MAX];
set<ll> s;

void Solve() {
    cin >> n >> k;
    for(ll i = 1; i <= n; i ++ ) cin >> a[i];
	ll l = 1, r = n * k + 1;
	while(l < r) {
		ll mid = l + r >> 1;
		ll sumDec = 0;
		for(ll i = 1; i <= k ; i ++ ) {
			ll dec = upper_bound(a + 1, a + n + 1, mid - sumDec) - a - 1;
			sumDec += dec; 
		}
		if(sumDec < mid) r = mid;
		else l = mid + 1;
	}
	cout << l << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}