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
    ll n; cin >> n;
    string s; cin >> s;
    ll ans = inf;
    for(ll i = 0; i < n - 1; i ++ ) {
        vector<ll> a;
        bool ff = 0;
        for(ll j = 0; j < n; j ++ ) {
            ll x; 
            if(j == i) {
                x = ll(s[j] - '0') * 10 + ll(s[j + 1] - '0');
            } else if(j == i + 1) {
                continue;
            } else {
                x = ll(s[j] - '0');
            }
            if(x == 0) {
                cout << "0" << "\n";
                return ;
            }
            a.push_back(x);
        }
        ll sum = 0;
        ff = 0;
        for(ll i = 0; i < n - 1; i ++ ) {
            if(a[i] == 1) continue;
            sum += a[i];
        }
        for(ll i = 0; i < n - 1; i ++ ) {
            if(a[i] != 1) {
                ff = 0; break;
            } else ff = 1;
        }
        if(ff) sum ++ ;
        ans = min(sum, ans);
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