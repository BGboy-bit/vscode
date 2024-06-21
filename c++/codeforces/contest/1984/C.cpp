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

vector<ll> AC(vector<ll> &a, ll mo) {
    if(a.size() == 2 || a.size() == 1) return a;
    vector<ll> b;
    ll n = a.size();
    if(mo == 1) {
        bool ff = 0;
        ll cnt = 0;
        for(ll i = 0; i < n; i ++ ) {
            if(i == 0) {
                if(a[i] >= 0) ff = 1;
                else ff = 0; 
                cnt += a[i];
            } else {
                if(a[i] >= 0 && ff == 0 || a[i] < 0 && ff == 1) {
                    b.push_back(cnt);
                    cnt = a[i]; ff = (ff == true ? false : true);
                } else {
                    cnt += a[i];
                }
            }
        }
        b.push_back(cnt);
    } else {
        for(ll i = 0; i < n; i ++ ) {
            if(i == 0) {
                if(a[i] < 0) b.push_back(a[i]);
                else {
                    b.push_back(a[i] + a[i + 1]);
                    i ++ ;
                } 
            } else {
                if(i != n - 1) {
                    b.push_back(a[i] + a[i + 1]);
                    i ++ ;
                } else {
                    b.push_back(a[i]);
                }
            }
        }
    }
    return AC(b, -mo);
}

void Solve() {
    ll n; cin >> n;
    vector<ll> a(n + 1), b;
    bool ff = 0;
    ll cnt = 0;
    for(ll i = 0; i < n; i ++ ) {
        cin >> a[i];
    }
    b = AC(a, 1);
    if(b.size() == 1) {
        cout << abs(b[0]) << "\n";
    } else {
        ll ans = max(abs(b[0] + b[1]), abs(abs(b[0]) + b[1]));
        cout << ans << "\n";
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