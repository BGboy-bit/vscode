#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int inf = 0x3f3f3f3f;
const int MAX = 2e5 + 10;
const int mod = 998244353;

ll cnt;
void quick_prime() {
    ll ans = 1; 
    ll n = 2;
    while(cnt) {
        if (cnt & 1) {
            ans = ans * n % mod;
        }
        cnt >>= 1;
        n = n * n % mod;
    }
    cout << ans - 1 << "\n";
}

void Solve() {
    cin >> cnt;
    cnt -- ;
    quick_prime();
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