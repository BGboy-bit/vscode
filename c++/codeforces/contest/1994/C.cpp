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
    ll n, x; cin >> n >> x;
    vector<ll> a(n + 1);
    ll ans = 0;
    vector<ll> pre(n + 1);
    vector<ll> cnt(n + 1), sum(n + 1);
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    vector<ll> f(n + 10);
    for(ll i = n; i >= 1; i -- ) {
        ll p = upper_bound(pre.begin() + i, pre.end(), pre[i - 1] + x) - pre.begin(); // pre[p] - pre[i - 1] >= x
        f[i] = (p - i) + f[p + 1];
        ans += f[i];
    }
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