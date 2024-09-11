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
    ll n; cin >> n;
    vector<ll> a(n + 1), b(n + 1);
    string s;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
        b[i] = a[i] + b[i - 1];
    }
    cin >> s; s = " " + s;
    vector<ll> l1, r1;
    for(ll i = 1; i <= n; i ++ ) {
        if(s[i] == 'L') l1.push_back(i);
    }
    for(ll i = n; i >= 1; i -- ) {
        if(s[i] == 'R') r1.push_back(i);
    }
    ll ans = 0;
    for(ll i = 0; i < min(l1.size(), r1.size()); i ++ ) {
        if(r1[i] > l1[i])
            ans += b[r1[i]] - b[l1[i] - 1];
    }
    cout << ans << '\n';
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