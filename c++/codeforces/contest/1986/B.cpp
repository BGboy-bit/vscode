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
    vector<vector<ll>> a(n + 1, vector<ll> (m + 1)); 
    for(ll i = 1; i <= n; i ++ ) {
        for(ll j = 1; j <= m; j ++ ) {
            cin >> a[i][j];
        }
    }
    for(ll j = 1; j <= m; j ++ ) {
        for(ll i = 1; i <= n; i ++ ) {
            vector<ll> x;
            if(i > 1) x.push_back(a[i - 1][j]);
            if(i < n) x.push_back(a[i + 1][j]);
            if(j > 1) x.push_back(a[i][j - 1]);
            if(j < m) x.push_back(a[i][j + 1]);
            if(x.size() == 0) continue;
            bool ff = 0;
            for(auto y : x) if(a[i][j] < y) {
                ff = 1; break;
            }
            if(ff) continue;
            a[i][j] = x[0];
            for(auto y : x) a[i][j] = max(a[i][j], y);
        }
    }
    for(ll i = 1; i <= n; i ++ ) {
        for(ll j = 1; j <= m; j ++ ) {
            cout << a[i][j] << " \n"[j == m];
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