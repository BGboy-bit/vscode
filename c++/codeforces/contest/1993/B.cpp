#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
typedef array<ll, 2> PII; // vector<PII> a(n + 1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int maxn = 2e5 + 10;
bool multi = 1;

void Solve() {
    ll n; cin >> n;
    vector<ll> a(n + 1);
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
    }
    ll maxx = 0, maxx1 = 0;
    sort(a.begin() + 1, a.end());
    for(ll i = 1; i <= n; i ++ ) {
        if(a[i] % 2 == 1) {
            maxx = max(a[i], maxx);
        } else {
            maxx1 = max(maxx1, a[i]);
        }
    }
    if(maxx == 0 || maxx1 == 0) {
        cout << "0\n"; return ;
    }
    ll ans = 0;
    for(ll i = 1; i <= n; i ++ ) {
        if(a[i] % 2 == 0) {
            if(maxx >= a[i]) {
                ans ++ ;
                maxx += a[i];
            } else {
                maxx += 2 * maxx1;
                ans += 2;
            }
        } 
    }
    cout << ans << "\n";
}


signed main() {
    // freopen("test.in","r",stdin);  
    // freopen("code.out","w",stdout);    
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}