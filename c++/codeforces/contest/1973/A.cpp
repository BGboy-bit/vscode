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
    ll a, b, c; cin >> a >> b >> c;
    if(a == b && b == c && a == 0) {
        if(a == 0) cout << "0" << "\n";
    } else if((a + b + c) % 2 != 0) {
        cout << "-1" << "\n";
    } else {
        if(c >= a + b) {
            cout << a + b << "\n";
        } else {
            cout << c + ((a + b) - c) / 2 << "\n";
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