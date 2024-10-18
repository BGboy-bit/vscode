#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
typedef array<ll, 2> PII; // vector<PII> a(n + 1);
const ll inf = 2e18 + 10;
// const int mod = 998244353;
const int maxn = 2e5 + 10;
bool multi = 0;

void Solve() {
    ll n; cin >> n;
    vector<ll> cat(110);
    cat[0] = 1; cat[1] = 1;
    for(ll i = 2; i <= n; i ++ ) {
        for(ll j = 1; j <= i; j ++ ) {
            cat[i] += cat[j - 1] * cat[i - j];
            cat[i] %= 100;
        }
    }
    cout << cat[n] << '\n';
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