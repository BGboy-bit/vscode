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
    ll n, x, k; cin >> n >> x >> k;
    string s; cin >> s;
    ll kk = k;
    for(ll i = 0; i < min(n, kk); i ++ ) {
        if(s[i] == 'L') x -- ;
        else x ++ ;
        k -- ;
        if(x == 0) {
            break;
        } 
    }
    if(x != 0) {
        cout << 0 << "\n"; return ;
    }
    ll cnt = 0, pos = 0;
    for(ll i = 0; i < n; i ++ ) {
        if(s[i] == 'L') cnt -- ;
        else cnt ++ ;
        if(cnt == 0) {
            pos = i + 1; break;
        }
    }
    if(pos == 0) cout << 1 << "\n";
    else cout << k / pos + 1 << "\n";
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