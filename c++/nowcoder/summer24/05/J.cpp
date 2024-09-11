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
    ll n, d, k; cin >> n >> d >> k;
    if(d == 1) {
        if(n == 2) cout << "1\n";
        else cout << "0\n";
        return ;
    }   

    ll pos1 = 2 * (d - 1) + (k - 2) * (d - 2);          // 边节点 中间节点
    ll pos2 = k - 1;                                    // 路
    ll ans = 1;
    for(ll i = 1; i <= n; i ++ ) ans = (ans * i) % mod; // 1 到 n 全排列
    for(ll i = k + 1; i <= n; i ++ ) {
        pos1 = (pos1 * (d + pos1 - 2) % mod + pos2 * (pos1 + d - 2) % mod) % mod;
        pos2 = (pos2 * (pos2 + 1)) % mod;
    }
    cout << ans << "\n";
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