
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

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}
ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

void Solve() {
    ll n = 50; cin >> n;
    vector<ll> a(n + 1);
    ll ans = 1;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
    }
    for(ll i = 1; i <= n; i ++ ) {
        ans = lcm(a[i], ans);
    }
    vector<ll> b(n + 1);
    ll cnt = 0;
    for(ll i = 1; i <= n; i ++ ) {
        b[i] = ans / a[i];
        cnt += b[i];
    }
    if(cnt >= ans) {
        cout << "-1" << "\n";
        return ;
    }
    for(ll i = 1; i <= n; i ++ ) {
        cout << b[i] << " \n"[i == n];
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