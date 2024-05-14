#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
typedef array<ll, 2> PII; // vector<PII> a(n+1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 1e5 + 10;
bool multi = 0;
ll v[MAX];
ll a[MAX];
ll n, len, k;  

bool check(ll md) {
    ll num = 0;
    ll less = 0;
    for(ll i = 1; i <= n + 1; i ++ ) {
        ll l = v[i] - v[less];
        if(v[i] + md > len) {
            return num >= k;
        }
        if(l >= md) {
            num ++ ;
            less = i;
        }
            
    }
    return num >= k;
}

void Solve() {
    cin >> n >> len;
    cin >> k;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> v[i];
    }
    v[n + 1] = len;
    // bin_search
    ll l = 1, r = len;
    while(l < r) {
        ll md = (l + r + 1) / 2;
        if(check(md)) {
            l = md;
        } else {
            r = md - 1;
        }
    }
    cout << l << "\n";
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