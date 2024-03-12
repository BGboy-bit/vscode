#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;

void exgcd(ll a, ll b, ll &gcd, ll &x, ll &y) {//拓展欧几里得算法
    if (b == 0) gcd = a, x = 1, y = 0;
    else exgcd(b, a % b, gcd, y, x), y -= x * (a / b);
}

void Solve() {
	ll a, b, c, gcd, x, y;
    cin >> a >> b >> c;//ax + by = c 
	exgcd(a, b, gcd, x, y);//gcd = gcd(a, b)
	if(c % gcd != 0) {//裴蜀定理
		cout << "-1" << "\n";
		return;
	}
	a /= gcd; b /= gcd; c /= gcd; 
	x = (x * c % b + b) % b; 
	y = (c * gcd - (a * gcd) * x) / (b * gcd);

	ll ans = inf;
	for(ll k = -8; k <= 8; k ++ ) {//玄学取k
		ll xx = x + k * b;
		ll yy = y - k * a;
		ans = min(ans, max(2 * (xx + yy), 2 * abs(xx - yy) - 1));
	}
	cout << ans << "\n";
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
