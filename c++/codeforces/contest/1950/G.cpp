#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll summ;
bool ac;

void dfs(vector<vector<ll>> &v, ll a, ll b, vector<ll> &vis) {
    if(!vis[a]) {
        vis[a] = 1; summ -- ;
        ll siza = 0;
        if(v[b].size() > 1) siza = 1;
        for(ll i = 0; i < v[a].size(); i ++ ) {
            ll nxt = v[a][i];
            if(vis[nxt] || nxt == b) continue;
            if(v[nxt].size() > 1) {
                siza ++ ;
                if(siza >= 3) ac = 0; 
            }
            dfs(v, a, nxt, vis);
        }        
    }

    if(!vis[b]) {
        vis[b] = 1; summ -- ;
        ll sizb = 0;
        if(v[a].size() > 1) sizb = 1;
        for(ll i = 0; i < v[b].size(); i ++ ) {
            ll nxt = v[b][i];
            if(vis[nxt] || nxt == a) continue;
            if(v[nxt].size() > 1) {
                sizb ++ ;
                if(sizb >= 3) ac = 0; 
            }
            dfs(v, b, nxt, vis);
        }         
    }
}

void Solve() {
    ll n; cin >> n;
    vector<string> g(n), w(n);
    for(ll i = 0; i < n; i ++ ) {
        cin >> g[i] >> w[i];
    }
    ll lo = 1 << n;
    ll ans = 100;
    for(ll i = 23; i < lo; i ++ ) {
        bitset<16> bt(i); 
        vector<string> ss, ss1;
        ll sum = 0;
        for(ll j = 0; j < n; j ++ ) {
            if(bt[j] == 1) {
                ss.push_back(g[j]); ss.push_back(w[j]);
                ss1.push_back(g[j]); ss1.push_back(w[j]);                
                sum ++ ;
            }
        }
        sort(ss.begin(), ss.end());
        ll cnt = 0; 
        map<string, ll> mp;
        for(ll j = 0; j < ss.size(); j ++ ) {
            if(!mp.count(ss[j])) {
                mp[ss[j]] = cnt ++ ;
            }
        }
        vector<vector<ll>> v(cnt);
        for(ll j = 0; j < ss1.size(); j += 2) {
            v[mp[ss1[j]]].push_back(mp[ss1[j + 1]]);
            v[mp[ss1[j + 1]]].push_back(mp[ss1[j]]);
        }
        vector<ll> vis(cnt);
        summ = cnt; ac = 1;
        dfs(v, 0, 1, vis);
        if(ac && summ == 0) ans = min(ans, n - sum);
        cout << ans << " " << i << '\n';
    }
    /*
    3 23
    2 55
    */
    cout << ans << "\n";
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