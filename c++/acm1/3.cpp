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
    db xa, ya, xb, yb;
    cin >> xa >> ya >> xb >> yb;
    ll minn = inf;
    for(db m = 2; m <= 10; m ++ ) {
        db a[20] = {1, m, -1, -m, 1, m, -1, -m};
        db b[20] = {m, 1, m, 1, -m, -1, -m, -1};
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
        db bx = xb + x[i], by = yb + y[i];
            // xb += x[i]; yb += y[i]; 
            for(ll j = 0; j < n; j ++ ) {
                for(ll k = j + 1; k < n; k ++ ) {
                    //db v = ((bx - xa) / a[j] - (by - ya) / b[j]) / (a[k] / a[j] - b[k] / b[j]);
                    db v = ((bx - xa) * b[j] - (by - ya) * a[j]) / (a[k] * b[j] - b[k] * a[j]);
                    if(v - round(v) > 1e-8 || v < 0) continue;
                    //db u = ((bx - xa) / a[k] - (by - ya) / b[k]) / (a[j] / a[k] - b[j] / b[k]);
                    db u = ((bx - xa) * b[k] - (by - ya) * a[k]) / (a[j] * b[k] - b[j] * a[k]);
                    if(u - round(u) > 1e-8 || u < 0) continue; 
                    minn = min(minn,(ll)(u + v));
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