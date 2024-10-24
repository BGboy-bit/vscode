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

ll n, k; 

bool Check(ll mid, vector<pair<ll, ll>> &a) {
    vector<ll> b;
    ll sum = 0;
    for(ll i = 1; i <= n; i ++ ) {
        if(a[i].first >= mid) {
            sum ++ ;
        } else if(a[i].second == 1) {
            b.push_back(i);
        }
    }
    reverse(b.begin(), b.end());
    ll kk = k;
    for(auto i : b) {
        if(kk >= mid - a[i].first) {
            kk -= (mid - a[i].first);
            sum ++ ;
        } else break;
    }
    if(sum > (n + 1 >> 1)) return true;
    else return false;
}  

void Solve() {
    cin >> n >> k;
    vector<pair<ll, ll>> a(n + 1);
    for(ll i = 1; i <= n; i ++ ) cin >> a[i].first;
    for(ll i = 1; i <= n; i ++ ) cin >> a[i].second;
    sort(a.begin() + 1, a.end());
    
    ll ans = 0;
    for(ll i = 1; i <= n; i ++ ) {
        if(a[i].second == 0) continue;
        ll mid;
        if(i <= n / 2) {
            mid = a[(n + 2) / 2].first;
        } else {
            mid = a[n / 2].first;
        }
        ans = max(ans, a[i].first + mid + k);
    }
    
    ll lo = 1, hi = 1e9;
    while(lo < hi) {
        ll mid = lo + hi + 1 >> 1;
        if(Check(mid, a)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    ans = max(ans, lo + a[n].first);
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