#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 1;//∂‡◊È ‰»Î

ll n;
struct node {
    ll w, num;
}b[MAX];
bool cmp(node u, node v) {
    if(u.w != v.w) return u.w < v.w;
    else return u.num < v.num;
}
ll a[MAX], c[MAX], d[MAX];
void Solve() {
    cin >> n;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i]; b[i].w = a[i]; b[i].num = i;
    }
    sort(b + 1, b + n + 1, cmp);
    unordered_map<ll, ll> mp;
    c[1] = b[1].w;
    for(ll i = 1; i <= n; i ++ ) {
        if(mp[b[i].w] == 0) mp[b[i].w] = i;
        c[i] = c[i - 1] + b[i].w;
    }
    d[n] = 0;
    for(ll i = n; i >= 1; i -- ) {
        d[i - 1] = d[i] + b[i].w;
    }
    // for(ll i = 1; i <= n; i ++ ) {
    //     ll num = mp[a[i]];
    //     ll ans = 0;
    //     ll r =  c[n]  - c[num] - (a[i] - 1) * (n - num);
    //     ll l = (a[i] + 1) * (num - 1) - (d[1] - d[num]);
    //     ans = l + r + 1; 
    //     cout << ans << " ";
    // }
    for(ll i = 1; i <= n; i ++ ) {
        a[b[i].num] = n + b[i].w * (2 * i - n) - c[i] + d[i];
    }
    for(ll i = 1; i <= n; i ++ ) {
        cout << a[i] << " ";
    }
    cout << "\n";
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