#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 1e6 + 10;

ll n, m, q;
struct node {
    ll type, line, op;
}l[MAX];


void Solve() {
    cin >> n >> m >> q;
    for(ll i = 1; i <= q; i ++ ) {
        string type, op; ll line;
        cin >> type >> line >> op;
        l[i].type = type == "row" ? 1 : 0;
        l[i].line = line;
        l[i].op = op == "on" ? 1 : 0;
    }

    ll ans = 0;
    ll cntc = m, cntr = n;
    vector<bool> r(n + 1, 0); vector<bool> c(m + 1, 0);
    for(ll i = q; i >= 1; i -- ) {
        if(l[i].type == 1) {// row
            if(r[l[i].line]) continue;//己经锁定
            ans += cntc * l[i].op;//只操作没有锁定的灯
            r[l[i].line] = 1;//标记锁定
            cntr -- ;//操作后不会被先前操作影响
        }
        
        else {// column
            if(c[l[i].line]) continue;
            ans += cntr * l[i].op;
            c[l[i].line] = 1;
            cntc -- ;
        }
    } 
    cout << ans << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    // cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}