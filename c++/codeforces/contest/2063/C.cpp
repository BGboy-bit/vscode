#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool cmp(pair<ll, ll> x, pair<ll, ll> y) {
    return x.second > y.second;
}

void Solve() {
    ll n; cin >> n;
    vector<ll> du(n + 1);
    map<pair<ll, ll>, ll> mp;
    vector<ll> g[n + 1];
    for(ll i = 1; i < n; i ++ ) {
        ll x, y; cin >> x >> y;
        du[x] ++ ; du[y] ++ ;
        mp[{x, y}] = 1; mp[{y, x}] = 1;
        g[x].push_back(y); g[y].push_back(x);
    }
    vector<pair<ll, ll>> pr;
    for(ll i = 1; i <= n; i ++ ) {
        pr.push_back({i, du[i]});
    }
    sort(pr.begin(), pr.end(), cmp);
    ll maxx = pr[0].second, pos = n - 1;
    ll cnt = 1;
    for(ll i = 1; i < n; i ++ ) {
        if(pr[i].second < maxx) {
            pos = i - 1;
            break;
        }
        cnt ++ ;
    }
    ll ans = 0;
    ll res = pr[0].first;
    if(cnt > 2) {
        bool ff = 0;
        for(ll i = 1; i <= pos; i ++ ) {
            if(mp[{pr[0].first, pr[i].first}] == 0) {
                ff = 1; break;
            }
        }
        if(!ff) res = pr[1].first;
    }
    for(auto x : g[res]) {
        du[x] -- ;
    }
    du[res] = 0;
    ll x = *max_element(du.begin() + 1, du.end());
    cout << maxx + x - 1 << "\n"; return ;
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