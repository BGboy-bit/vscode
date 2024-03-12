#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;

void Prime(ll x) {
    
}


ll k, c, n;

ll Check(ll b) {
    if((c - b) % k != 0) return 0;
    ll a = (c - b) / k;
    if(a == 0) return 0;
    if(__gcd(a, b) >= n) return 1;
    else return 0;
}

void Solve() {
    ll ans = 0;
    cin >> k >> c >> n;
    for(ll i = 1; i * i <= c; i ++ ) {
        if(c % i == 0) {
            ans += Check(i);
            if(c / i != i) {
                ans += Check(c / i);
            }
        }
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