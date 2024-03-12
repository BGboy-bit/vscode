#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;

ll n, m, k;

ll ksm(ll a ,ll k) {//a代表底数，k代表大指数
    a %= mod;
    ll rec = 1;
    while(k)
    {
        if (k & 1)
            rec = rec * a % mod;
        k >>= 1;
        a = a * a % mod;
    }
    return rec;
}

void Solve() {
    cin >> n >> m >> k;
    if(n != k) cout << ksm(m, n - k) << "\n";
    else cout << ksm(m, n) << "\n";
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