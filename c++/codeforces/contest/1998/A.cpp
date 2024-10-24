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
    ll x, y, k; cin >> x >> y >> k;
    for(ll i = 1; i < k; i ++ ) {
        if(i % 2 == 0) {
            cout << x + i - 1 << " " << y + i - 1 << "\n";
        } else {
            cout << x - i << " " << y - i << "\n";
        }
    }
    if(k % 2 == 0) {
        cout << x + k - 1 << " " << y + k - 1 << "\n";
    } else {
        cout << x << " " << y << "\n";
    }
}


signed main() {
    // freopen("test.in","r",stdin);  
    // freopen("code.out","w",stdout);    
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}