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

ll a[520];

void Solve() {
    ll n; cin >> n;
    ll res = 500;
    ll x = 1, y = 1;
    vector<ll> ans;
    while(n > 0) {
        while(a[res] > n) {
            res -- ;
        } 
        while(a[res] <= n) {
            n -= a[res];
            for(ll i = 1; i <= res + 1; i ++ ) {
                ans.push_back(x ++ );
                ans.push_back(y);
            }
            y ++ ;
        }
    } 
    cout << ans.size() / 2 << "\n";
    x = ans.size() - 1;
    for(ll i = 0; i < x; i += 2) {
        cout << ans[i] << " " << ans[i + 1] << "\n";
    }
}


signed main() {
    // freopen("test.in","r",stdin);  
    // freopen("code.out","w",stdout);    
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for(ll i = 1; i <= 500; i ++ ) {
        a[i] = a[i - 1] + i;
    }
    ll T = 1;
    if(multi) cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}