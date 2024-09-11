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
    string a, b, c; cin >> a >> b >> c;
    ll cnt12 = 0, cnt13 = 0, cnt23 = 0, cnt123 = 0;
    for(ll i = 0; i < n; i ++ ) {
        if(a[i] == b[i] && a[i] == c[i]) cnt123 ++ ;
        else if(a[i] == b[i]) cnt12 ++ ;
        else if(a[i] == c[i]) cnt13 ++ ;
        else if(b[i] == c[i]) cnt23 ++ ;
    }
    ll cnta = cnt123, cntb = cnt123, cntc = cnt123;
    ll minn = min(cnt12, min(cnt13, cnt23));
    cnt12 -= minn; cnt13 -= minn; cnt23 -= minn;
    cnta += minn * 2; cntb += minn * 2; cntc += minn * 2;
    cnta += (cnt12 + 1) / 2 + (cnt13 + 1) / 2 + cnt23 - (cnt23 + 1) / 2;
    cntb += (cnt12 + 1) / 2 + (cnt23 + 1) / 2 + cnt13 - (cnt13 + 1) / 2;
    cntc += (cnt13 + 1) / 2 + (cnt23 + 1) / 2 + cnt12 - (cnt12 + 1) / 2;
    cout << min(cnta, min(cntb, cntc)) << "\n";
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