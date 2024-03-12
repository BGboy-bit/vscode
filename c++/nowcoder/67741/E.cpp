#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
typedef array<ll, 2> PII; // vector<PII> a(n+1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 200;
bool multi = 1;//¶à×éÊäÈë

ll a[MAX];

void Solve() {
    ll n, m; cin >> n >> m;
    for(ll i = 1; i <= n; i ++ ) cin >> a[i];
    for(ll i = 1; i <= m; i ++ ) {
        
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