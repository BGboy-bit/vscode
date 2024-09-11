#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, q, ans, siz; 
const int N = 1e7;
vector<ll> prime;

void dfs(ll x, ll s, ll o) {
	if(x == siz) {
		ans += o * (n / s); return ;
	}
	dfs(x + 1, s, o);
	if(s <= n / prime[x]) {
		dfs(x + 1, s * prime[x], -o);
	}
} 

void init() {
	ans = 0; prime.clear();
}

void Solve() {
	cin >> n >> q;
	while(q -- ) {
		ll u, v; cin >> u >> v;
		if(__gcd(u, v) == 1) {
			cout << "1 1" << "\n"; continue;
		}
		init();
		ll u1 = u, v1 = v;
        for(ll i = 2; i <= sqrt(u); i ++ ) {
            if(u % i == 0) {
                prime.push_back(i);
                while(u % i == 0) u /= i;
			}
        }
        if(u > 1) {
            prime.push_back(u);
        }
        for(ll i = 2; i <= sqrt(v); i ++ ) {
            if(v % i == 0) {
                if(u1 % i != 0) prime.push_back(i);
                while(v % i == 0) v /= i;
            }
        }
        if(v > 1 && u1 % v != 0) {
            prime.push_back(v);
        }
		siz = prime.size();
		dfs(0, 1, 1);
		if(__gcd(u1, v1) == 2) ans ++ ;
		cout << "2 " << ans << "\n";
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	ll T = 1;
//	cin >> T;
	while(T -- ) {
		Solve();
	}
	return 0;
}

