#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef double db;

const int MAX = 2e5 + 10;
ll n;
vector<vector<ll>> graph;
vector<ll> v(MAX);
ll cnt[MAX], sum[MAX];
bool vis[MAX];

ll SUM(ll i) {
    if(cnt[i] == 1 && vis[graph[i][0]] == 1) sum[i] = 1;
    else if(sum[i] == 0) {
        vis[i] = 1;
        for(ll j = 0; j < cnt[i]; j ++ ) {
            ll x = graph[i][j];
            if(vis[x] == 0) sum[i] += SUM(x);
        }       
    }
    return sum[i];
}

void Solve() {
    memset(cnt, 0, sizeof(cnt));
    memset(sum, 0, sizeof(sum));
    memset(vis, 0, sizeof(vis));
    //build tree
    cin >> n;
    ll x, y;
    for(ll i = 1; i <= n + 1; i ++ ) {
        graph.push_back(v);
    }
    for(ll i = 1;i < n; i ++ ) {
        cin >> x >> y;
        graph[x][cnt[x] ++ ] = y;
        graph[y][cnt[y] ++ ] = x;
    } 
    
    SUM(1);

    //algorithm 
    ll q;
    cin >> q; 
    while(q -- ) {
        cin >> x >> y;
        cout << sum[x] * sum[y] << "\n";
    }
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