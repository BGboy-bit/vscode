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
    ll n, k; cin >> n >> k;
    if(n % 2 == 0 && k <= n * n / 2 && k % 2 == 0 || n % 2 == 1 && k <= (n + 1) * (n - 1) / 2 && k % 2 == 0) {
        cout << "Yes" << "\n";
        vector<ll> a(n + 1);
        for(ll i = 1; i <= n; i ++ ) a[i] = i;
        ll r = n + 1;
        for(ll l = 1; k > 0; l ++ ) {
            while(r -- ) {
                if((r - l) * 2 <= k) {
                    k -= (r - l) * 2;
                    a[l] = r; a[r] = l;
                    break;
                } 
            }
        }
        for(ll i = 1; i <= n; i ++ ) {
            cout << a[i] << " \n"[i == n];
        }
    } else cout << "No" << "\n";
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