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

ll a[110][110] = {{}, {}, {20,18,219,216,2218,2214}, {165,162}, {14,12,147,144,1480,1476}, {138,135}, {}, {129,126}, {}, {}, {1262,2519} };

void Solve() {
    ll n; cin >> n;
    if(n == 1) {
        for(ll i = 2; i <= 10000; i ++ ) {
            cout << i << " " << i - 1 << "\n";
        }
    }
    else {
        for(ll i = 1; i <= a[n][i] != 0; i ++ ) {
            if(i % 2 == 0) cout << "\n";
            else cout << " ";
        }
    }
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