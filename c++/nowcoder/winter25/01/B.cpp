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
bool multi = 0;

void Solve() {
    ll n; cin >> n;
    vector<ll> a(n + 1), b;
    for(ll i = 1; i < n; i ++ ) {
        ll u, v; cin >> u >> v;
        a[u] ++ ; a[v] ++ ;
    }
    for(ll i = 1; i <= n; i ++ ) {
        if(a[i] == 1) {
            b.push_back(i);
        } else if(a[i] > 2) {
            cout << "-1\n"; return ;
        }
    }
    if(b.size() > 2) {
        cout << "-1\n"; return ;
    }
    cout << b[0] << " " << b[1] << "\n";
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