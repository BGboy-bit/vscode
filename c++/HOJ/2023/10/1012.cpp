#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 5e5 + 10;
bool multi = 1;//¶à×éÊäÈë

ll n;
ll a[MAX];



void Solve() {
    cin >> n;
    vector<bool> ff(n + 1, 0);
    unordered_map<ll, ll> mp;
    ll minn = inf, maxx = 0;
    for(ll i = 1; i <= n; i ++ ) {
        ll x; cin >> x;
        mp[x] ++ ;
        maxx = max(mp[x], maxx);
        minn = min(minn, x);
    }
    if(mp[minn] == maxx) cout << "YES" << "\n";
    else cout << "NO" << "\n";
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}