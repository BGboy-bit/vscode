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
    string s; cin >> s;
    vector<ll> a(m + 1), cnt(n + 1, 0), b;
    for(ll i = 1; i <= m; i ++ ) {
        cin >> a[i];
    }
    string c; cin >> c; sort(c.begin(), c.end());
    sort(a.begin() + 1, a.end());
    for(ll i = 1; i <= m; i ++ ) {
        if(cnt[a[i]] == 0) {
            b.push_back(a[i]);
            cnt[a[i]] = 1;
        }  
    }
    for(ll i = 0; i < b.size(); i ++ ) {
        s[b[i] - 1] = c[i];
    }
    cout << s << "\n";
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