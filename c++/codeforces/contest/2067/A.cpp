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
    ll x, y; cin >> x >> y;
    if(x <= y) {
        if(y - x == 1) {
            cout << "Yes\n"; return ;
        }  else {
            cout << "No\n"; return ;
        }
    } else {
        ll z = x - y;
        if((z - 8) % 9 == 0) {
            cout << "Yes\n"; return ;
        } else {
            cout << "No\n"; return ;
        }
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