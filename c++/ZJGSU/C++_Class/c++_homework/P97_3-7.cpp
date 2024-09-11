#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;
typedef unsigned short int usi;
typedef short int si;

const db PI=acos(-1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 0;//¶à×éÊäÈë

si AC(usi x, usi y) {
    return y == 0 ? -1 : x / y;
}

void Solve() {
    usi x, y;
    cin >> x >> y;
    cout << AC(x, y) << "\n";
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