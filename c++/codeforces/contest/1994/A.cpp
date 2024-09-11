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
    ll n, m; cin >> n >> m;
    vector<vector<ll>> a(n + 1, vector<ll>(m + 1));
    for(ll i = 1; i <= n; i ++ ) {
        for(ll j = 1; j <= m; j ++ ) {
            cin >> a[i][j];
        }
    }
    if(n == 1 && m == 1) {
        cout << "-1" << "\n";
        return ;
    }
    if(m >= 2) {
        for(ll i = 1; i <= n; i ++ ) {
            for(ll j = 1; j <= m; j ++ ) {
                if(j == m) cout << a[i][1] << "\n";
                else cout << a[i][j + 1] << " ";
            }
        } 
    } else {
        for(ll i = 1; i <= n; i ++ ) {
            if(i == n) cout << a[1][1] << "\n";
            else cout << a[i + 1][1] << "\n";
        }
    }

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