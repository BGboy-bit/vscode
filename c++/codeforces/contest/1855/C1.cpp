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
    ll n;
    cin >> n;
    ll a[30];
    bool ff = 0; ll res; ll cnt = 0;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
        if(a[i] > 0) {ff = 1; res = i;} 
        if(a[i] < 0) cnt ++ ;
    }
    if(ff) {
        cout << 5 + n + cnt << "\n";
        for(ll i = 1; i <= 5; i ++ ) cout << res << " " << res << "\n";
        if(a[1] >= 0) cout << 1 << " " << res << "\n";
        else {
            cout << 1 << " " << res << "\n";
            cout << 1 << " " << res << "\n";
        }
        for(ll i = 2; i <= n ;i ++ ) {
            if(a[i] >= 0) cout << i << " " << i - 1 << "\n";
            else {
                cout << i << " " << i - 1 << "\n";
                cout << i << " " << i - 1 << "\n";
            }
        }
    }
    else {
        cout << n - 1 << "\n";
        for(ll i = n; i > 1; i -- ) cout << i - 1 << " " << i << "\n"; 
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