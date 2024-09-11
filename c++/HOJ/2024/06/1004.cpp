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
    ll n, m; cin >> n >> m;
    vector<ll> al(n + 1), ar(n + 1), bl(m + 1), br(m + 1);
    for(ll i = 1; i <= n; i ++ ) {
        cin >> al[i] >> ar[i];
    }
    for(ll i = 1; i <= m; i ++ ) {
        cin >> bl[i] >> br[i];
    }
    ll res = 1, x;
    for(ll i = 1; i <= m; i ++ ) {
        if(br[i] > al[res]) {
            cout << "No\n"; return ;
        }
        if(i < m)
            x = min(br[i] + 2 * (br[i] - bl[i]), bl[i + 1]);
        else 
            x = br[i] + 2 * (br[i] - bl[i]);
        ll pos = lower_bound(al.begin() + res + 1, al.end(), x) - al.begin();
        if(x < ar[pos - 1]) {
            cout << "No\n"; return ;
        }
        res = pos;
    }
    if(res == n + 1)
        cout << "Yes\n";
    else 
        cout << "No\n";
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