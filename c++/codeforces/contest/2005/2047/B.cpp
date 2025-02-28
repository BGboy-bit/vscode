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
    string s; cin >> s;
    vector<ll> a(26);
    for(ll i = 0; i < n; i ++ ) {
        a[s[i] - 'a'] ++ ;
    }
    ll maxx = 0, maxp, maxc, minn = maxn, minp = 0, minc;
    for(ll i = 0; i < n; i ++ ) {
        ll x = s[i] - 'a';
        if(maxx < a[x] || maxx == a[x] && x > maxc) {
            maxx = a[x]; maxp = i; maxc = x;
        }
        if(minn > a[x] || minn == a[x] && x < minc) {
            minn = a[x]; minp = i; minc = x;
        }
    }
    s[minp] = s[maxp];
    cout << s << "\n";
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