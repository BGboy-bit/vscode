#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

ll divMod(string str, ll num)
{
	int s = 0;
	for(auto i : str)
		s = (s * 10 + i -'0') % num;
	return s;
}

const db PI = acos(-1);
typedef array<ll, 2> PII; // vector<PII> a(n+1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 0;

void Solve() {
    string a; cin >> a;
    ll b; cin >> b;
    ll ans = 0;
    vector<ll> c;
    c.push_back(1); c.push_back(b);
    for(ll i = 2; i <= __lg(b); i ++ ) {
        if(b % i == 0) {
            c.push_back(i);
            c.push_back(b / i);
        }
    }
    sort(c.begin(), c.end());
    reverse(c.begin(), c.end());
    for(auto i : c) {
        if(divMod(a, i) == 0) {
            cout << i << "\n";
            return ;
        }
    }
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    while(T--) {
        Solve();
    }
    return 0;
}
