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
    vector<vector<ll>> a(n + 1, vector<ll>(m + 1)), b(n + 1, vector<ll>(m + 1));
    for(ll i = 1; i <= n; i ++ ) {
        for(ll j = 1; j <= m; j ++ ) {
            char c; cin >> c;
            a[i][j] += c - '0';
        }
    }
    for(ll i = 1; i <= n; i ++ ) {
        for(ll j = 1; j <= m; j ++ ) {
            char c; cin >> c;
            b[i][j] += c - '0';
        }
    }

    for(ll i = 1; i < n; i ++ ) {
        for(ll j = 1; j < m; j ++ ) {
            if(a[i][j] != b[i][j]) {
                ll diff = (b[i][j] - a[i][j] + 3) % 3;
                a[i][j] = b[i][j];
                a[i + 1][j] = (a[i + 1][j] + 2 * diff) % 3;
                a[i][j + 1] = (a[i][j + 1] + 2 * diff) % 3;
                a[i + 1][j + 1] = (a[i + 1][j + 1] + diff) % 3;
            }
        }
    }

    for(ll i = 1; i <= n; i ++ ) {
        for(ll j = 1; j <= m; j ++ ) {
            if(a[i][j] != b[i][j]) {
                cout << "No" << "\n";
                return ;
            }
        }
    }
    cout << "Yes" << "\n";
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