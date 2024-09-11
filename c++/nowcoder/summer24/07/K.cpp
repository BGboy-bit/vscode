#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;
#define int ll 
const db PI = acos(-1);
typedef array<ll, 2> PII; // vector<PII> a(n + 1);
const ll inf = 2e18 + 10;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 10;
bool multi = 0;

int dis(string s) {
    vector<int> last(26, -1);
    int n = s.size();
    vector<int> f(n, 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 26; ++j) {
            if (last[j] != -1) {
                f[i] = (f[i] + f[last[j]]) % mod;
            }
        }
        last[s[i] - 'a'] = i;
    }
    int ans = 0;
    for (int i = 0; i < 26; ++i) {
        if (last[i] != -1) {
            ans = (ans + f[last[i]]) % mod;
        }
    }
    return ans;
}

void Solve() {
    ll n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    // if(s == t) {
    //     cout << 1 << '\n'; return ;
    // }
    ll res = 0, pos = 0, pos1 = 0;
    vector<ll> p (n + 1, -1);
    for(ll i = 0; i < n; i ++ ) {
        if(s[i] == t[res]) {
            res ++ ;
            pos = i;
            p[i] = res;
            if(res == m) break;
        }
        p[i] = res;
    }
    if(res < m) {
        cout << 0 << "\n"; return ;
    }
    res = 0;
    for(ll i = n - 1; i >= 0; i -- ) {
        if(s[i] == t[res]) {
            res ++ ;
            pos1 = i;
            if(res == m) break;
        }
    }
    if(res < m) {
        cout << 0 << "\n"; return ;
    }
    string ss;
    for(ll i = pos + 1; i < pos1; i ++ ) {
        ss += s[i];
    }
    ll ans = dis(ss);
    if(pos < pos1) ans = (ans + 1) % mod;
    
    vector<int> d1(m);
    for (int i = 0, l = 0, r = -1; i < m; i++) {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < m && t[i - k] == t[i + k]) {
            k ++ ;
        }
        // cout << k << " " << i - k << " " << i + k << "\n";
        d1[i] = k -- ;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
    vector<int> d2(m);
        for (int i = 0, l = 0, r = -1; i < m; i++) {
            int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
            while (0 <= i - k - 1 && i + k < m && t[i - k - 1] == t[i + k]) {
                k++;
        }
        d2[i] = k--;
        if (i + k > r) {
            l = i - k - 1;
            r = i + k;
        }
    }    
    vector<ll> d(m);
    for(ll i = 0; i < m; i ++ ) {
        ll p1 = i - d1[i] + 1;
        ll p2 = i - d2[i];
        d[p1] = max(d[p1], d1[i] * 2 - 1); 
        d[p2] = max(d[p2], d2[i] * 2);
    }
    ll x = p[pos1] == -1 ? m - 1 : p[pos1] - 1;
    for(ll i = 0; i <= x; i ++ ) {
        if(d[i] + i == m) ans = (ans + 1) % mod;
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