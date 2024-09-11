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
    vector<ll> vis(n + 1);
    bool ac = 1;
    for(ll i = 1; i <= n; i ++ ) {
         cin >> a[i];
        if(i == 1) vis[a[i]] = 1;
        else {
            bool f1 = 1, f2 = 1;
                if(a[i] == 1 || vis[a[i] - 1] == 0) {
                    f1 = 0;
                }
                if(a[i] == n || vis[a[i] + 1] == 0) {
                    f2 = 0;
            }
            if(!f1 && !f2) ac = 0;
            vis[a[i]] = 1; 
        }  
    }
    if(!ac) cout << "No\n";
    else cout << "Yes\n";
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