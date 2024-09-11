#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
typedef array<ll, 2> PII; // vector<PII> a(n + 1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int maxn = 2e5 + 10;
bool multi = 1;

void Solve() {
    ll n, k; cin >> n >> k;
    char a[n + 1][n + 1];
    for(ll i = 1; i <= n; i ++ ) {
        for(ll j = 1; j <= n; j ++ ) {
            cin >> a[i][j];
        }
    }
    for(ll i = k; i <= n; i += k) {
        for(ll j = k; j <= n; j += k) {
            cout << a[i][j];
            if(j == n) cout << "\n";
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