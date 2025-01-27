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

void Solve() {
    ll n; cin >> n;
    vector<pair<pair<ll, ll>, ll>> a(n + 1);
    for(ll i = 1; i <= n; i ++ ) {
        ll l, r; cin >> l >> r;
        a[i] = {{l, r}, i};
    }
    sort(a.begin() + 1, a.end(), 
        [](auto &u, auto &v){
            return u.first.second < v.first.second 
                || (u.first.second == v.first.second 
                    && u.first.first < v.first.first);
        }
    );
    set<ll> s;
    for(ll i = 1; i <= n; i ++ ) {
        s.insert(i);
    }
    vector<ll> ans(n + 1);
    for(ll i = 1; i <= n; i ++ ) {
        ll l = a[i].first.first;
        ll r = a[i].first.second;
        ll idx = a[i].second;
        auto ii = s.lower_bound(l);
        if(ii == s.end() || *ii > r) {
            cout << -1 << "\n"; return ;
        }
        ans[idx] = *ii;
        s.erase(ii);
    }
    for(ll i = 1; i <= n; i ++ ) {
        cout << ans[i] << " \n"[i == n];
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