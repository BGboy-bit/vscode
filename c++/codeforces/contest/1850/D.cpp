#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI=acos(-1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 1;//¶à×éÊäÈë

ll a[MAX]; 

void Solve() {
    ll n, k; cin >> n >> k;
    for(ll i = 1; i <= n; i ++ ) cin >> a[i];
    sort(a + 1, a + n + 1);
    ll cnt = 0;
    vector<ll> b(n + 1, 1);
    for(ll i = 1; i < n; i ++ ) {
        if(a[i + 1] - a[i] <= k) b[cnt] ++ ;
        else cnt ++ ;
    }
    sort(b.begin(), b.end());
    cout << n - b[n] << "\n";
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