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

ll a[MAX];
ll b[MAX];

void Solve() {
    ll n, x;
    cin >> n >> x;
    a[0] = 0;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
        b[i] = a[i] - a[i - 1];
    }
    b[n + 1] = 2 * (x - a[n]);
    sort(b + 1, b + n + 2);
    cout << b[n + 1] << "\n";
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