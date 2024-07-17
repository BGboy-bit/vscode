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

void Solve() {
    ll i; cin >> i;

    if(i == 1) {
        cout << 9999 << "\n";
        for(ll j = 2; j <= 10000; j ++ ) {
            cout << j << " " << j - 1 << "\n";
        }
         return ;
    }
    vector<ll> aaa;
	// for(ll i = 1; i <= 100; i ++ ) {
        // cout << i << "\n";
		string s;
        string ss;
		ll ii = i;
		while(ii > 0) {
			s += ii % 10 + '0' ; ii /= 10;
		}
		reverse(s.begin(), s.end());
		for(ll x = 1; x <= 10000; x ++ ) {
				ss += s;
                ll cnt = 0;
                ll cnt1 = i * x;
                while(cnt1 != 0) {
                    cnt1 /= 10; cnt ++ ;
                }
			for(ll y = ss.length() - cnt - 1; y <= 10000; y ++ ) {
                ll ans1 = 0;
                ll ans2 = max(i * x - y, 0ll);
                if(ss.length() <= y) break; 
                else {
                    for(ll j = 0; j < ss.length() - y; j ++ ) {
                        ans1 = ans1 * 10 + ss[j] - '0';
                    }
                }
                if(ans1 == ans2) {
                    aaa.push_back(x);
                    aaa.push_back(y);
                }
			}
		}
        cout << aaa.size() / 2 << "\n";
        for(ll j = 0; j < aaa.size(); j ++ ) {
            cout << aaa[j];
            if(j % 2 == 1) cout << "\n";
            else cout << " ";
        }
        // cout << "\n";
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