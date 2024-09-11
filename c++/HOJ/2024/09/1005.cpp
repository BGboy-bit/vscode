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
    ll k, x, y; cin >> k >> x >> y;
    ll xx = (k + x - 1) / x;
    ll yy = (k + y - 1) / y;
    if(xx == yy) {
        if(xx % 2 == 1) {
            cout << "Yes\nNo\n";
        } else {
            cout << "No\nYes\n";
        }
    } else {
        cout << "Yes\nYes\n";
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