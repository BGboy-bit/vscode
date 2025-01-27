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

ll a[] = {1, 3, 6, 10, 15, 21, 28, 36};
ll n;

void Solve() {
    cin >> n;
    cout << "Yes\n";
    for(ll i = 0; i <= n; i ++ ) {
        for(ll j = i; j <= n; j ++ ) {
            cout << a[j] - i << " ";
        }
        ll x = a[n] - i;
        for(ll j = 1; j <= 2 * (n - i - 1); j ++ ) {
            if(j % 2 == 1) {
                x -- ;
            } else {
                x -= n - j / 2 + 1;
            }
            cout << x << " ";
        }
    }
    for(ll i = 1; i < n; i ++ ) {
        cout << a[n - i - 1] + 1 << " ";
    }
    cout << "1\n"; 
}


signed main() {
    // freopen("test.in","r",stdin);  
    // freopen("code.out","w",stdout);    
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
} 