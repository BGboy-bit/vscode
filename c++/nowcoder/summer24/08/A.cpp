#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
typedef array<ll, 2> PII; // vector<PII> a(n + 1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int maxn = 1e5 + 10;
bool multi = 1;

void Solve() {
    ll n; cin >> n;
    vector<ll> a(maxn + 10);
    for(ll i = 1; i <= n; i ++ ) {
        ll x; cin >> x;
        a[x] = 1;
    }
    ll cnt = 0;
    for(ll i = maxn; i >= 1; i -- ) {
        ll x = 0;
        if(a[i] == 1) continue;
        for(ll j = 1; j * i <= maxn; j ++ ) {
            if(a[j * i]) {
               if(x == 0) x = j * i;
               else x = __gcd(x, j * i); 
            }
        }
        if(x == i) {
            cnt ++ ;
            a[i] = 1;
        }
    }
    if(cnt % 2 == 1) cout << "dXqwq\n";
    else cout << "Haitang\n";
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