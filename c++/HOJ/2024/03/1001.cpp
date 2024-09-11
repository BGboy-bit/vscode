#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
//typedef array<ll, 2> PII; // vector<PII> a(n + 1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 1e6 + 10;
bool multi = 0;

vector<vector<ll>> a(MAX, vector<ll>()); 
vector<ll> ans(MAX);
vector<ll> tree(MAX);

void init() {
    for(ll i = 2; i <= 1000000; i ++ ) {
        for(ll j = i; j <= 1000000; j += i) {
            a[j].push_back(i);
        }
    }
//    for(ll i = 1; i <= 10 ; i ++ ) cout << a[i].size() << " \n"[i == 10];
    for(ll i = 1; i <= 1000000; i ++ ) {
        tree[i] = a[i].size() + 1 + tree[i - 1];
    } 
}

void Solve() {
    ll n; cin >> n;
    ans[1] = 1;
    for(ll i = 2; i <= n; i ++ ) {
        ans[i] = 1;                                              // all root
        for(auto j : a[i]) ans[i] = (ans[i] + ans[j] - 1) % mod; // multi root
        ll x = i - 1;              
        ans[i] = (ans[i] + tree[x]) % mod;                       // one root
    }
    // for(ll i = 1; i <= n; i ++ ) cout << tree[i] << " \n"[i == n];
    for(ll i = 1; i <= n; i ++ ) cout << ans[i] << " \n"[i == n];
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    init();
    ll T = 1;
    if(multi) cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}