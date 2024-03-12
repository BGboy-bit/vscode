#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 0;//¶à×éÊäÈë

db a[MAX], b[MAX];

void Solve() {
    ll n; cin >> n;
    ll ans = 0;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i]; b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    if(n % 2 == 0) {
        for(ll i = 1; i <= n; i ++ ) {
            if(a[i] <= b[n / 2]) cout << fixed << setprecision(1) << b[n / 2 + 1] << "\n";
            else cout << fixed << setprecision(1) << b[n / 2] << "\n";
        }
    }
    else {
        for(ll i = 1; i <= n; i ++ ) {
            if(a[i] <= b[n / 2]) cout << fixed << setprecision(1) << (b[n / 2 + 1] + b[n / 2 + 2]) / 2 << "\n";
            else if(a[i] == b[n / 2 + 1]) cout << fixed << setprecision(1) << (b[n / 2] + b[n / 2 + 2]) / 2 << "\n";
            else cout << fixed << setprecision(1) << (b[n / 2] + b[n / 2 + 1]) / 2 << "\n";
        }
    }
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