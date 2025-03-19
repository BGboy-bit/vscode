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
    ll n, q; cin >> n >> q;
    vector<ll> w(n + 1);
    for(ll i = 1; i <= n; i ++ ) {
        cin >> w[i];
    }
    vector<ll> pre(n + 1);
    for(ll i = 1; i <= n; i ++ ) {
        pre[i] = pre[i - 1] ^ w[i];
    }
    vector<vector<ll>> b(n + 1, vector<ll> (40));
    for(ll i = 1; i <= n; i ++ ) {
        if(i > 1) b[i] = b[i - 1];
        b[i][__lg(w[i])] = i;
        for(ll j = 30; j >= 0; j -- ) {
            b[i][j] = max(b[i][j], b[i][j + 1]);
        }
    }
    while(q -- ) {
        ll x; cin >> x;
        ll idx = n, nxt = n;
        while(idx > 0 && x > 0) {
            ll msb = __lg(x);
            nxt = b[idx][msb];
            x ^= pre[idx] ^ pre[nxt];
            idx = nxt;
            if(x < w[idx] || nxt == 0) {
                break;
            }
            x ^= w[idx]; idx -- ;
        }
        cout << n - idx << " ";
    }
    cout << "\n";
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