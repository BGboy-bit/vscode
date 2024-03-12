#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 0;//¶à×éÊäÈë

void Solve() {
    ll n; cin >> n;
    string a, b; cin >> a >> b;
    ll ans = 0;
    for(ll i = 0; i < n; i ++ ) {
        if(a[i] == 'N' && b[i] == 'Y' || a[i] == 'Y' && b[i] == 'N') ans += 2;
        else if(a[i] == 'Y' && b[i] == 'Y') ans += 3;
    }
    cout << ans << "\n";
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