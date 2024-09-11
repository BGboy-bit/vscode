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
    vector<PII> a(n + 1);
    for(ll i = 1; i <= n; i ++ ) cin >> a[i][0] >> a[i][1];
    ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    ll t = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    for(ll i = 1; i <= n; i ++ ) {
        ll x = (a[i][0] - x2) * (a[i][0] - x2) + (a[i][1] - y2) * (a[i][1] - y2);
        if(x <= t) {
            cout << "No\n"; return ;
        }
    }
    cout << "Yes\n";
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