#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 1e6 + 10;
bool multi = 1;//��������

ll res[MAX];

void Solve() {
    ll n;
    cin >> n;
    cout << lower_bound(res, res + MAX + 1, n) - res << "\n";
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for(ll i = 1; i <= MAX; i ++ ) {
        ll siz = i / 2 + 1;
        ll lth = 2 * i;
        res[i] = siz * lth + i;
    }
    ll T = 1;
    if(multi) cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}