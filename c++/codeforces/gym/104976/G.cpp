#include<bits/stdc++.h>
using namespace std;
//typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
typedef array<ll, 2> PII; // vector<PII> a(n+1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 3010;
bool multi = 0;

ll dx[] = {0, 0, 1, -1};
ll dy[] = {1, -1, 0, 0};

unordered_map<ll, ll> tim;
unordered_map<ll, ll> val;
// unordered_map<ll, ll> val_bfs;

char mp[MAX][MAX];
void Solve() {
    ll n, m, k; cin >> n >> m >> k;
    ll sx, sy;
    for(ll i = 1; i <= k; i ++ ) {
        ll x, y; cin >> x >> y;
        tim[x * m + y] = 1;
        val[x * m + y] = k - i + 1;
        if(i == 1) sx = x, sy = y;
    }
    for(ll i = 1; i <= n; i ++ ) {
        for(ll j = 1; j <= m; j ++ ) {
            cin >> mp[i][j]; 
        }
    }
    queue<array<ll, 3>> q;
    q.push({sx, sy, 1});
    while(!q.empty()) {
        ll x = q.front()[0], y = q.front()[1], now = q.front()[2];
        q.pop();
        for(ll i = 0; i < 4; i ++ ) {
            ll xx = x + dx[i], yy = y + dy[i];
            if(xx < 1 || xx > n || yy < 1 || yy > m || mp[xx][yy] == '#') continue;
            if(tim[xx * m + yy] == 1) {
                ll cnt = min(val[xx * m + yy] ,now + max((ll)0, (val[xx * m + yy] - now)));
            }
        }
    }   
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}