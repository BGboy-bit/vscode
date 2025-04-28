#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
using pii = pair<int,int>;

constexpr ll N =2E6 + 10, inf = 2E18 + 10;

void solve()
{
    ll x, y, r, vx, vy; cin >> x >> y >> r >> vx >> vy;
    ll lx, ly, rx, ry; cin >> lx >> ly >> rx >> ry;
    lx += r; rx -= r; ly += r; ry -= r;
    if(lx > rx || ly > ry) {
        cout << "No\n"; return ;
    }
    if(vy == 0) {
        if(y >= ly && y <= ry && (vx < 0 && x >= lx || vx > 0 && x <= rx || vx == 0 && x >= lx && x <= rx)) {
            cout << "Yes\n"; return ;
        } else {
            cout << "No\n"; return ;
        }
    }
    if(vx == 0) {
        if(x >= lx && x <= rx && (vy < 0 && y >= ly || vy > 0 && y <= ry || vy == 0 && y >= ly && y <= ry)) {
            cout << "Yes\n"; return ;
        } else {
            cout << "No\n"; return ;
        }
    }
    if(vx < 0) {
        if(lx > x) {
            cout << "No\n"; return ;
        }  else {
            rx = min(x, rx);
        }
    } else {
        if(rx < x) {
            cout << "No\n"; return ;
        } else {
            lx = max(lx, x);
        }
    }
    ly = ly * vx, ry = ry * vx;
    ll f1 = vy * lx + y * vx - vy * x;
    ll f2 = vy * rx + y * vx - vy * x;
    if(f1 > f2) swap(f1, f2);
    if(ly > ry) swap(ly, ry);
    if(f1 >= ly && f1 <= ry || f2 >= ly && f2 <= ry || f1 < ly && f2 > ry) {
        cout << "Yes\n"; return ;
    } else {
        cout << "No\n"; return ;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    cin>>T;
    while(T--){
        solve();
    }

    return 0;
}