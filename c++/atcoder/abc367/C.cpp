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
bool multi = 0;

ll n, k; 
vector<ll> ans; 
void dfs(ll dep, vector<ll> &a, ll summ, vector<ll> b) {
    for(ll i = 1; i <= a[dep]; i ++ ) {
        if(dep == n) {
            if((summ + i) % k == 0) {
                for(auto j : b) {
                    ans.push_back(j);
                }
                ans.push_back(i);
            }
        } else {
            b.push_back(i);
            dfs(dep + 1, a, summ + i, b);
            b.pop_back();
        }
    }
}

void Solve() {
    cin >> n >> k;
    vector<ll> a(n + 1);
    for(ll i = 1; i <= n; i ++ ) cin >> a[i];
    vector<ll> b;
    dfs(1, a, 0, b);
    for(ll i = 0; i < ans.size(); i ++ ) {
        cout << ans[i] << " \n"[(i + 1) % n == 0];
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