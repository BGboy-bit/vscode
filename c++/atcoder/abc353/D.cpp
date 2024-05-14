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
bool multi = 0;

ll cntt(ll x) {
    ll cnt = 1; 
    while(x % 10 != x) {
        cnt ++ ;
    }
    return cnt;
}

ll cc[10][20];

void Solve() {
    ll n; cin >> n;
    vector<ll> a(n + 1), b(n + 1);
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
        b[i] = cntt(a[i]);
    }
    for(ll i = 1; i <= n; i ++ ) {
        
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