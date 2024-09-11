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
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
    }
    ll m; cin >> m;
    for(ll i = 1; i <= m; i ++ ) {
        map<char, ll> mp;
        map<ll, char> mp1;
        string s; cin >> s;
        s = " " + s;
        if(s.length() != n + 1) {
            cout << "No\n"; continue;
        }
        bool ac = 1;
        for(ll i = 1; i <= n; i ++ ) {
            if(!mp.count(s[i]) && !mp1.count(a[i])) {
                mp[s[i]] = a[i];
                mp1[a[i]] = s[i];
            } else if(mp.count(s[i]) && mp[s[i]] != a[i] || mp1.count(a[i]) && mp1[a[i]] != s[i]) {
                    cout << "No\n"; ac = 0; break;
            }
        }
        if(ac) cout << "Yes\n";
    }
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