#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
const ll inf = 1e9 + 1;
const int mod = 998244353;
const int MAX = 1e4 + 10;
bool multi = 0;//多组输入

ll a[MAX], b[MAX];
ll n;

ll ac(ll mid) {
    for(ll i = 1; i <= n; i ++ ) {
        if(a[i] / mid > b[i]) return 1;//偏小
        else if(a[i] / mid < b[i]) return -1;//偏大
    }
    return 0;
}

void Solve() {
    cin >> n;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i] >> b[i];
    }
    //left
    ll l = 1, r = inf;
    while(l != r) {
        ll mid = l + r >> 1;
        if(ac(mid) <= 0) r = mid;
        else l = mid + 1;
    }
    cout << l << " ";
    //right
    l = 1; r = inf;
    while(l != r) {
        ll mid = l + r + 1 >> 1;
        if(ac(mid) >= 0) l = mid;
        else r = mid - 1;
    }
    cout << r << "\n";
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