#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 5010;
bool multi = 1;//¶à×éÊäÈë

ll a[MAX], mx[MAX], mn[MAX];

void Solve() {
    ll n; 
    //cin >> n; 
    n = 5000;
    for(ll i = 1; i <= n; i ++ ) {
        //cin >> a[i];
        a[i] = n - i + 1;
    }
    ll ans = n * (n + 1) / 2;
    ll minn = a[n], maxx = a[1];
    set<pair<ll, ll>> s;
    for(ll i = 1; i <= n; i ++ ) {
        ll cntl = 0, cntr = 0;  
        for(ll l = i; l >= 1; l -- ) {
            if(a[l] > a[i]) cntr ++ ; else if (a[l] < a[i]) cntl ++ ;
            ll cnt1 = cntl, cnt2 = cntr;
            if(cnt2 > n - i || i - l > a[i] - 1) break;
            for(ll r = i; r <= n; r ++ ) {
                if(a[r] > a[i]) cnt2 ++ ; else if(a[r] < a[i]) cnt1 ++ ; 
                if(cnt1 == i - l && cnt2 == r - i && !s.count({l, r})) {
                    s.insert({l, r}); ans -- ; 
                }
                else if(cnt1 > i - l || r - i > n - a[i]) break; 
            }
        }  
    }
    cout << ans << "\n";
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) 
    //cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}