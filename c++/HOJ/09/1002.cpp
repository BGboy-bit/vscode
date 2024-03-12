#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 1;//∂‡◊È ‰»Î

unordered_map<ll, ll> mp;
ll n;
ll dfs(ll n) {
    if(n == 1) return 0;
    if(mp[n]) return mp[n];
    ll cnt;
    if(n >= 2) {
        cnt = n % 2 + dfs(n / 2) + 1;
    } 
    if(n >= 3) {
        cnt = min(cnt, n % 3 + dfs(n / 3) + 1);
    }
    return mp[n] = cnt;
}

void Solve() {
    cin >> n;
    cout << dfs(n) << "\n";
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}