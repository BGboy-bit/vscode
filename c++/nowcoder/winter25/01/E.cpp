#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
typedef array<ll, 2> PII; // vector<PII> a(n + 1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int maxn = 2e5 + 10;
bool multi = 1;

void Solve() {
    ll n; cin >> n;
    vector<ll> a(n + 1);
    map<ll, ll> mp;
    ll max11 = 0, max12 = 0, max21 = 0, max22 = 0;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
        mp[a[i]] ++ ;
        if(max11 < mp[a[i]]) {
            max21 = max11; max22 = max12;
            max11 = mp[a[i]]; max12 = a[i];
        } else if(max21 < mp[a[i]]) {
            max21 = mp[a[i]]; max22 = a[i];
        }
    }
    if(max21 == 0) {
        cout << n / 2 << "\n"; return ;
    }
    
}


signed main() {
    // freopen("test.in","r",stdin);  
    // freopen("code.out","w",stdout);    
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}