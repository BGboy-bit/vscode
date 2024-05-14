#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
typedef array<ll, 2> PII; // vector<PII> a(n+1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 3e5 + 10;
bool multi = 1;

ll a[MAX], b[MAX], c[MAX];
void Solve() {
    ll n; cin >> n;
    ll cnt = 0;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
        if(a[i] != a[i - 1]) cnt = 0;
        b[i] = ++ cnt;
    }
    cnt = 0;
    for(ll i = n; i >= 1; i -- ) {
        if(a[i] != a[i + 1]) cnt = 0;
        c[i] = ++ cnt;
    }
    ll ans = inf;
    for(ll i = 2; i <= n - 1; i ++ ) {
        if(a[i] != a[i - 1]) {
            if(a[i + 1] != a[i - 1]) {
                cout << "0" << "\n";
                return ;
            } else {
                ans = min(ans, min(b[i - 1], c[i + 1]));
                a[i] = a[i - 1];
            }
        }
    }
    if(ans != inf) cout << ans << "\n";
    else cout << "-1" << "\n";
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