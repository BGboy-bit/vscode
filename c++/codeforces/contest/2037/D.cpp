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
    ll n, m, l; cin >> n >> m >> l;
    vector<pair<ll, ll>> hur;
    for(ll i = 1; i <= n; i ++ ) {
        ll l1, r1; cin >> l1 >> r1;
        hur.push_back({l1, r1 - l1 + 2});
    }
    vector<pair<ll, ll>> pup;
    for(ll i = 1; i <= m; i ++ ) {
        ll x, v; cin >> x >> v;
        pup.push_back({x, v});
    }
    // priority_queue<ll, vector<ll>, greater<ll>> nw;
    vector<ll> nw;
    priority_queue<ll, vector<ll>, less<ll>> res;
    ll pos = 0, sum = 1;
    for(auto h : hur) {
        ll st = h.first, val = h.second;
        while(pup[pos].first < st && pos < pup.size()) {
            res.push(pup[pos ++ ].second);
        }
        while(sum < val && !res.empty()) {
            ll x = res.top(); res.pop();
            sum += x; nw.push_back(x);
        }
        if(sum < val) {
            cout << "-1\n"; return ;
        }
        // while(!nw.empty() && sum - nw.top() >= val) {
        //     sum -= nw.top(); nw.pop();
        // }
    }
    cout << nw.size() << "\n";
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