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
    vector<ll> a(n + 1);
    ll cnt = 0;
    ll maxx = -1;
    ll tnc = 0;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
        cnt |= a[i];
        if(cnt > maxx) {
            maxx = cnt;
            tnc = i;
        }
    }
    ll l = 2, res = 0, ans = tnc;
    for(ll i = 2; i <= tnc + 1; i ++ ) {
        res |= a[i];
    }
    tnc ++ ;
    while(tnc <= n && l <= n) {
        while(res != cnt && tnc <= n) {
            res |= a[ ++ tnc]; 
            ans ++ ;   
        }
        l ++ ;
        if(tnc == n) {
            ll x = 0;
            for(ll i = l; i <= n; i ++ ) {
                x |= a[i];
            }
            if(res != cnt || x != cnt) {
                cout << n - l + 2 << "\n"; 
            } else {
                cout << ans << "\n";
            }
            return ;
        }
        res = 0, tnc ++ ;
        for(ll i = l; i <= tnc; i ++ ) {
            res |= a[i];
        }
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