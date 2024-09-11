#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
typedef array<ll, 2> PII; // vector<PII> a(n+1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 1;

void Solve() {
    ll n; cin >> n;
    vector<ll> a(n + 1);
    for(ll i = 1; i <= n; i ++ ) cin >> a[i];
    ll cnt = 2;
    ll ans = 0;
    ll sum = 0;
    vector<ll> b(n + 1, 0);
    for(ll i = 1; i <= n; i ++ ) {
        if(b[i] == 1) continue;
        b[i] = 1;
        if(a[i] != i) {
            b[a[i]] = 1;
            ll j = a[i];
            while(b[a[j]] == 0) {
                cnt ++ ;
                b[a[j]] = 1;
                j = a[j];
            }
            if (cnt == 2) {
                sum += 1;
            } else if(cnt == 4) {
                ans += 1;
            } else {
                ans += (cnt + 2) / 3;
            }
            cnt = 2;
        } 
        
    }
    ans += (sum + 1) / 2;
    cout << ans << "\n";
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