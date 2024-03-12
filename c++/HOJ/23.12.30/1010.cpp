#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 200;
bool multi = 1;//¶à×éÊäÈë

ll v[MAX], w[MAX];

void Solve() {
    ll n; cin >> n;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> v[i];
    }
    for(ll i = 1; i <= n; i ++ ) {
        cin >> w[i];
    }
    sort(v + 1, v + n + 1);
    sort(w + 1, w + n + 1);
    for(ll i = 1; i <= n; i ++ ) {
        if(v[i] < w[i]) {
            cout << "NO" << "\n";
            return;
        }
    }
    cout << "YES" << "\n";
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