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

void Solve() {
    ll n, l, r; cin >> n >> l >> r;
    ll res = 0;  // 需要运输的人数
    ll cnt = 0;  // 可以运输的次数
    ll cntt = 0; // 只能运输一次的次数
    for(ll i = 1; i <= n; i ++ ) {
        ll a; cin >> a; 
        if(a <= 2) res ++ ;
        else {
            cnt += (a - 1) / 2;
            if(a % 2 == 0) cntt ++ ;
        }
    }
    cnt /= l;
    if((r - l) * cnt >= res || (res - (r - l) * cnt) <= cntt) cout << "Yes" << "\n";
    else cout << "No" << "\n";
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