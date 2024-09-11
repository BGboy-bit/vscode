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
    ll n, q; cin >> n >> q;
    string a, b; cin >> a >> b;
    a = ' ' + a; b = ' ' + b;
    vector<vector<ll>> cnt(n + 1, vector<ll>(26));
    for(ll i = 1; i <= n; i ++ ) {
        for(ll j = 0; j < 26; j ++ ) {
            cnt[i][j] = cnt[i - 1][j];
        }
        cnt[i][a[i] - 'a'] ++ ;
        cnt[i][b[i] - 'a'] -- ;
    }
    while(q -- ) {
        ll l, r; cin >> l >> r;
        ll sum = 0;
        for(ll i = 0; i < 26; i ++ ) {
            sum += abs(cnt[r][i] - cnt[l - 1][i]);
        }
        sum /= 2;
        cout << sum << "\n";
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