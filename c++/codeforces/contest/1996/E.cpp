#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
typedef array<ll, 2> PII; // vector<PII> a(n + 1);
const ll inf = 2e18 + 10;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 10;
bool multi = 1;

string s;
ll  ans = 0;
map<PII, ll> a;
vector<ll> cnt(maxn);

ll dfs(ll l, ll r) {
    if(l == r) {
        a[{l, r}] = 0;
        return 0;
    }
    else if(l == r - 1) {
        if(s[l] == s[r]) {
            a[{l, r}] = 0;
            return 0;
        } else {
            a[{l, r}] = 1;
            return 1;
        }
    }
    if(cnt[r] - cnt[l - 1] == 0) a[{l, r}] = 1;
    else a[{l, r}] = 0;
    return a[{l, r}] = (a[{l, r}] + (dfs(l, r - 1) + dfs(l + 1, r) - a[{l + 1, r - 1}])) % mod;
}

void dfs1(ll l, ll r) {
    if(l == r) return ;
    ans = (ans + a[{l, r}]) % mod;
    dfs1(l + 1, r); dfs1(l, r - 1);
}

void Solve() {
    ans = 0;
    cin >> s;
    ll n = s.size();
    s = " " + s; 
    for(ll i = 1; i <= n; i ++ ) cnt[i] = cnt[i - 1] + (s[i] == '1' ? 1 : -1);
    dfs(1, n);
    dfs1(1, n);
    cout << ans << "\n";
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}