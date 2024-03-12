#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef int ll;
typedef double db;

const ll inf = 0x3f3f3f3f;
const int mod = 998244353;
const int MAX = 5e3 + 10;
bool multi = 0;//∂‡◊È ‰»Î

ll n, m;
ll graph[MAX][MAX];
ll prepoint[MAX], lowcost[MAX];

void Prim(ll st) {
    ll ans = 0;
    for(ll i = 1; i <= n; i ++ ) {
        if(i != st) lowcost[i] = graph[st][i];
        else lowcost[i] = 0;
        prepoint[i] = st;
    }
    ll minn = inf, pos;
    for(ll i = 1; i < n; i ++ ) {
        minn = inf;
        for(ll j = 1; j <= n; j ++ ) {
            if(lowcost[j] < minn && lowcost[j] > 0) {
                minn = lowcost[j]; pos = j;
            }
        }
        if(minn == inf) {cout << "orz" << "\n"; return; }
        ans += minn; lowcost[pos] = 0;
        for(ll j = 1; j <= n; j ++ ) {
            if(lowcost[j] > graph[pos][j]) {
                lowcost[j] = graph[pos][j]; prepoint[j] = pos;
            }
        }
    }
    cout << ans << "\n";
}

void Solve() {
    memset(graph, inf, sizeof(graph));
    cin >> n >> m;
    for(ll i = 1; i <= m; i ++ ) {
        ll x, y, z;
        cin >> x >> y >> z;
        graph[x][y] = min(graph[x][y], z); graph[y][x] = min(graph[y][x], z);
    }   
    Prim(1);
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}