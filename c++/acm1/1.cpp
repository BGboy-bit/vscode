#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 1;//¶à×éÊäÈë

db x[5] = {0, 1, -1, 1, -1};
db y[5] = {0, -1, 1, 1, -1};

void Solve() {
    ll xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;
    ll minn = inf;
    ll min1, min2;
    for(ll m = 2; m <= 10; m ++ ) {
        ll a[20] = {1, m, -1, -m, 1, m, -1, -m};
        ll b[20] = {m, 1, m, 1, -m, -1, -m, -1};
        ll n = 8;
        if(m == 7) {
            n += 4;
            a[8] = 5; a[9] = -5; a[10] = 5; a[11] = -5;
            b[8] = 5; b[9] = 5; b[10] = -5; b[11] = -5; 
        }
        else if(m == 8) {
            n += 8;
            a[8] = 4; a[9] = -4; a[10] = 4; a[11] = -4; a[12] = 7; a[13] = -7; a[14] = 7; a[15] = -7;
            b[8] = 7; b[9] = 7; b[10] = -7; b[11] = -7; b[12] = 4; b[13] = 4; b[14] = -4; b[15] = -4;
        }
        for(ll i = 0; i <= 4; i ++) {
        ll bx = xb + x[i], by = yb + y[i];
            //
            for(ll j = 0; j < n; j ++ ) {
                for(ll k = j + 1; k < n; k ++ ) {
                    if((a[k] * b[j] - b[k] * a[j]) == 0) continue;
                    if(((bx - xa) * b[j] - (by - ya) * a[j]) % (a[k] * b[j] - b[k] * a[j]) != 0 || ((bx - xa) * b[j] - (by - ya) * a[j]) / (a[k] * b[j] - b[k] * a[j]) < 0) continue;
                    db v = ((bx - xa) * b[j] - (by - ya) * a[j]) / (a[k] * b[j] - b[k] * a[j]);
                    if((a[j] * b[k] - b[j] * a[k]) == 0) continue;
                    if(((bx - xa) * b[k] - (by - ya) * a[k]) / (a[j] * b[k] - b[j] * a[k]) < 0 || ((bx - xa) * b[k] - (by - ya) * a[k]) % (a[j] * b[k] - b[j] * a[k]) != 0) continue;
                    db u = ((bx - xa) * b[k] - (by - ya) * a[k]) / (a[j] * b[k] - b[j] * a[k]);
                    minn = min(minn,(ll)(u + v)); 
                    //if(minn == u + v) {min1 = u; min2 = v;}
                }
            }
        }
    }
    if(minn == inf) cout << "-1" << "\n";
    else cout << minn << "\n"; 
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