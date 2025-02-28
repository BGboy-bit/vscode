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
    vector<ll> a;
    for(ll i = 0; i < n; i ++ ) {
        if(s[i] == 'u') a.push_back(i);
    }
    ll pos = 0, ans = 0;
    while(1) {
        pos = s.find("uwawauwa", pos + 1);
        if(pos == string::npos) break;
        ll x = (lower_bound(a.begin(), a.end(), pos - 1) - a.begin());
        ans += (lower_bound(a.begin(), a.end(), pos - 1) - a.begin());
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