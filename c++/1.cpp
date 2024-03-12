#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
typedef array<int, 2> PII;
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 1e6 + 10;
bool multi = 0;//¶à×éÊäÈë


void Solve() {
    
    ll n; cin >> n;
    vector<PII> a(n + 1);
    for(ll i = 1; i <= n; i ++ ) {
      cin >> a[i][0];
      a[i][1] = i;
    }
    sort(a.begin() + 1, a.end());
    db sum  = 0, ans = 0;
    for(ll i = 1; i <= n; i ++ ) {
        cout << a[i][1] << " \n"[i == n];
        if(i != n) {
            sum += a[i][0];
            ans += sum;
        }
    }
    cout << fixed << setprecision(2) << ans / n << "\n";
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