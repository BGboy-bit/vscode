#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 1e6 + 10;



void Solve() {
    
    ll k;
    cin >> k;
    vector<ll> a[k], b;
    for(ll i = 0; i < k; i ++ ) {
        ll c;
        cin >> c;
        for(ll j = 1; j <= c; j ++ ) {
            ll x;
            cin >> x;
            a[i].push_back(x);
            b.push_back(x);
        } 
        sort(a[i].begin(), a[i].end());
    }
    sort(b.begin(), b.end());
    ll ans = inf;
    for(ll i = 0; i < b.size(); i ++ ) {
        bool f = 0; ll sum = 0;
        for(ll j = 0; j < k; j ++ ) {
            ll res = lower_bound(a[j].begin(), a[j].end(), b[i]) - a[j].begin();
            if(res == a[j].size()) {
                f = 1; break;
            }
            sum = max(sum, a[j][res] - b[i]);
        }
        if(f) break;
        ans = min(sum, ans);
    }
    cout << ans << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}