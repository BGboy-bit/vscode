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
    vector<ll> a(n + 1, -1);
    ll pos = -1;
    for(ll i = 2; i <= n; i ++ ) {
        cout << "? " << 1 << " " << i << endl;
        ll x; cin >> x;
        if(x > 0) {
            a[i] = 1;
            for(ll j = i - 1; j >= 1; j -- , x -- ) {
                if(x > 0) 
                    a[j] = 0;
                else 
                    a[j] = 1;
            }
            pos = i - 1; break;
        }
    }
    if(pos == -1) {
        cout << "! IMPOSSIBLE" << endl; return;
    }
    ll res = 1;
    for(ll i = pos + 2; i <= n; i ++ ) {
        cout << "? " << pos << " " << i << endl;
        ll x; cin >> x;
        if(x == res) 
            a[i] = 0;
        else {
            res = x; a[i] = 1;
        }     
    }
    for(ll i = 1; i <= n; i ++ ) {
        if(a[i] == -1) {
            cout << "! IMPOSSIBLE" << endl; return;
        }
    }
    cout << "! ";
    for(ll i = 1; i <= n; i ++ ) {
        cout << a[i];
    }
    cout << endl;
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