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
    ll n, x, y; cin >> n >> x >> y;
    ll z;
    if(y % 2 == 1) z = 1;
    else z = 0; 
    for(ll i = 1; i <= y; i ++ ) {
        if(i % 2 == z) cout << 1 << " ";
        else cout << -1 << " ";
    }
    for(ll i = y + 1; i <= x; i ++ ) {
        cout << 1 << " ";
    }
    ll ff = 1;
    for(ll i = x + 1; i <= n; i ++ ) {
        if(ff) {
            cout << -1 << " ";
            ff = 0;
        } else {
            cout << 1 << " ";
            ff = 1;
        }
    }
    cout << "\n";
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