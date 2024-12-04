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
    ll n, b, c; cin >> n >> b >> c;
    if(b == 0) {
        if(c >= n) cout << n << "\n";
        else if(c >= n - 2) cout << n - 1 << "\n";
        else cout << "-1\n";
    } else {
        if(c < n) 
            cout << n - 1 - max((n - c - 1) / b, 0ll) << "\n";
        else 
            cout << n << "\n";
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