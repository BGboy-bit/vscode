#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
typedef array<ll, 2> PII; // vector<PII> a(n + 1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int maxn = 1e3 + 10;
bool multi = 0;

ll n; 
ll a[maxn];

// bool check(ll x) {
//     ll l = 1, r = n;
//     ll cnt1 = 0, cnt2 = 0;
//     for(ll i = l + r >> 1; i >= 1; i ++ ) {
        
//     }
// }

void Solve() {
    cin >> n;
    for(ll i = 1; i <= n; i ++ ) cin >> a[i];
    ll ans = 0;
    for(ll i = 1; i <= n; i ++ ) {
        ll l = 1, r = n;
        ll cnt = 0;
        while(l < r) {
            ll mid = l + r + 1 >> 1;
            ll sum = 0;
            for(ll i = l; i <= r; i ++ ) sum += a[i];
            sum /= r - l + 1;
            ll pos = lower_bound(a + 1, a + n + 1, sum) - a - 1;
            if(sum > a[i]) {
                if(pos - l == 1) break;
                 r = mid - 1;
            } else if(sum < a[i]) {
                if(r - pos == 1) break;
                l = mid;
            } else break;
            cnt += abs(sum - a[i]);
        }
        ans = max(cnt, ans);
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