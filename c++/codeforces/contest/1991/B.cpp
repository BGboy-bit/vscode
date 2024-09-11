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
    ll n; cin >> n;
    vector<ll> b(n + 1), a(n + 1);
    for(ll i = 1; i < n; i ++ ) {
        cin >> b[i];
    }
    a[1] = b[1]; a[n] = b[n - 1];
    for(ll i = 1; i < n - 1; i ++ ) {
        a[i + 1] = b[i] | b[i + 1];
    }
    for(ll i = 1; i < n; i ++ ) {
        if(b[i] != (a[i] & a[i + 1])) {
            cout << "-1" << "\n";
            return ;
        }
        // cout << (a[i] & a[i + 1]) << " \n"[i == n];
    }
    for(ll i = 1; i <= n; i ++ ) cout << a[i] << " \n"[i == n];
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