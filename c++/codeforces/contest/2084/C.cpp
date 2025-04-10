#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n; cin >> n;
    vector<ll> a(n + 1), b(n + 1);
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
    }
    for(ll i = 1; i <= n; i ++ ) {
        cin >> b[i];
    }
    map<ll, ll> mp;
    vector<ll> c; c.push_back(0);
    ll cnt = 0;
    for(ll i = 1; i <= n; i ++ ) {
        ll x = min(a[i], b[i]), y = max(a[i], b[i]);
        if(mp.count(x) && mp[x] != y || x == y && (cnt == 1 && n % 2 == 1 || n % 2 == 0)) {
            cout << "-1\n"; return ;
        } else {
            if(x == y) cnt ++ ;
            mp[x] = y;
            c.push_back(x);
        }
    }
    vector<pair<ll, ll>> ans;
    if(n % 2 == 1) {
        for(ll i = 1; i <= n; i ++ ) {
            if(mp[c[i]] == c[i]) {
                if(i != (n + 1) / 2) {
                    swap(c[i], c[(n + 1) / 2]);
                    ans.push_back({i, (n + 1) / 2}); 
                }
            }
        }
    }
    map<ll, ll> mp2;
    for(ll i = 1; i <= n; i ++ ) {
        if(!mp2.count(c[i]) || mp2[c[i]] == i) {
            mp2[c[i]] = n + 1 - i;
        } else {
            ans.push_back({i, mp2[c[i]]});
            swap(c[i], c[mp2[c[i]]]);
            i -= 1;
        }
    }
    cout << ans.size() << "\n";
    for(auto [x, y] : ans) {
        cout << x << " " << y << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1; cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}