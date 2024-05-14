#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 1;//¶à×éÊäÈë

ll n;

struct node {
    ll l, r;
}e[MAX];

void Solve() {
    cin >> n;
    for(ll i = 1; i <= n; i ++ ) {
        ll l, r, a, b; 
        cin >> l >> r >> a >> b;
        e[i].l = l; e[i].r = b;
    }
    ll q; cin >> q;
    for(ll i = 1; i <= q; i ++ ) {
        ll x;
        cin >> x;
        
    } 
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