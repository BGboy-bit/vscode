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

#include <iostream>
#include <vector>
using namespace std;

vector<ll> pri;

void getpri() {
    vector<bool> isPrime(100010, 1);
    isPrime[0] = isPrime[1] = 0;
    for (ll i = 2; i * i <= 100000; i++) {
        if (isPrime[i]) {
            for (ll j = i * i; j <= 100000; j += i) {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i <= 100000; i++) {
        if (isPrime[i]) {
            pri.push_back(i);
        }
    }
}

void Solve() {
    ll n; cin >> n;
    ll pr = *upper_bound(pri.begin(), pri.end(), n / 3); 
    vector<ll> ans, vis(n + 1);
    ans.push_back(pr); vis[pr] = 1;
    for(ll i = 1; i + pr <= n && pr - i >= 1; i ++ ) {
        ans.push_back(pr - i); ans.push_back(pr + i);
        vis[pr - i] = 1, vis[pr + i] = 1;
    }
    for(ll i = 1; i <= n; i ++ ) {
        if(!vis[i]) ans.push_back(i);
    }
    for(ll i = 0; i < n; i ++ ) {
        cout << ans[i] << " \n"[i == n - 1];
    }
}


signed main() {
    // freopen("test.in","r",stdin);  
    // freopen("code.out","w",stdout);    
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    getpri();
    while(T -- ) {
        Solve();
    }
    return 0;
}