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
bool multi = 0;

ll maxx = 2e5 + 10;

void Solve() {
    ll n;  cin >> n;
    vector<ll> a(maxx, 0);
    for(ll i = 1; i <= n; i ++ ) {
        ll x; cin >> x;
        a[x] ++ ;
    }
    ll ans = 0;
    for(ll i = 1; i < maxx; i ++ ) {
        for(ll j = i; j < maxx; j += i) {
            if(__gcd(j ^ i, j) == i && (i ^ j) < maxx) {
                ans += a[i ^ j] * a[j];
            }
        }
    }
    cout << ans / 2 << "\n";
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