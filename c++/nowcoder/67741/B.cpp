#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
typedef array<ll, 2> PII; // vector<PII> a(n + 1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 0;//¶à×éÊäÈë

void Solve() {
    ll n; cin >> n;
    bool let = 0, rit = 0;
    vector<ll> vl1, vl2, vr1, vr2;
    for(ll i = 1; i <= n; i ++ ) {
        ll r, c; cin >> r >> c;
        if(r == 1) {
            if(c <= 0) {
                vl1.push_back(c); let = 1;
            } else {
                vr1.push_back(c); rit = 1;
            }
        }
        else {
            if(c <= 0) {
                vl2.push_back(c); let = 1;
            } else {
                vr2.push_back(c); rit = 1;
            }
        }
    }
    ll ans = 0;
    if(let == 0) {
        
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