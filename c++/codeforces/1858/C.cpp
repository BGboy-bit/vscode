#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 1;//¶à×éÊäÈë

void Solve() {
    ll n; cin >> n;
    vector<bool> ff(n + 1, 0);
    for(ll i = 1; i <= n; i ++ ) {
        if(ff[i]) continue;
        for(ll j = i; j <= n; j *= 2) {
            cout << j << " ";
            ff[j] = 1;
        }
    }
    cout << "\n";
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}