// P3197 [HNOI2008] 越狱
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 100003;

ll quick_mod(ll a, ll n) {
    ll ans = 1;
    while(n) {
        if(n & 1) {
            ans = ans * a % mod;
            n -- ;
        }
        a = a * a % mod;
        n /= 2;
    }
    return ans;  
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll m, n; cin >> m >> n;
    // cout << quick_mod(m, n) << "\n";
    cout << (quick_mod(m, n) - ((m % mod) * quick_mod(m - 1, n - 1)) % mod + mod) % mod << "\n";
    return 0;
}