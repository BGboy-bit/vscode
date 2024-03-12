#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int MAX = 2e5 + 10;


ll vis[MAX];
ll n, m, s, t;
vector<vector<ll>> graph;
vector<ll> v(MAX, 0);
vector<vector<ll>> mp;
ll cnt[MAX];

void Solve() {
    cin >> n >> m;
    ll x, y;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> x >> y;
        mp[x][cnt[x] ++ ] = y;
    }
    for(ll i = 1; i <= n; i ++ ) {
        vector<ll> v(cnt[i], 0);
        graph.push_back(v);
    }

    for(ll i = 1; i <= m; i ++ ) {
        cin >> s >> t;
        memset(vis, 0, sizeof(vis));
        
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    // cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}