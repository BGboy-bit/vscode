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
    ll n; cin >> n;
    ll x = 5 - 2 * n;
    if(n == 2) {
        cout << "1 -3 -3 1" << "\n";
        return ;
    } else if(n == 3) {
        cout << "1 -10 6 6 -10 1" << "\n";
        return ;
    }
    cout << "1 1 1 2 ";
    for(ll i = 5; i < 2 * n - 1; i ++ ) {
        if(i % 2 != 0) cout << "-1 ";
        else cout << "2 ";
    }
    cout << x << " 1" << "\n";
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