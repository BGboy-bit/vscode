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

ll dx[] = {1, -1, 0, 0};
ll dy[] = {0, 0, 1, -1};

ll ans = maxn;
queue<ll> x00, y00;
ll n, m; 

ll dfs(ll x, ll y, ll res, vector<vector<ll>> &vis, vector<vector<ll>> &a) {
    for(ll i = 0; i <= 3; i ++ ) {
        ll xx = x + dx[i], yy = y + dy[i];
        if(xx <= 0 || yy <= 0 || xx > n || yy > m || vis[xx][yy] == 1) continue;
        if(a[xx][yy] == 1) {
            vis[xx][yy] = 1;
            res += dfs(xx, yy, 0, vis, a);
        } else {
            vis[xx][yy] = 1;
            res ++ ; 
            x00.push(xx), y00.push(yy);
        }
    }
    return res;
}

void Solve() {
    cin >> n >> m;
    vector<vector<ll>> a(n + 1, vector<ll>(m + 1)), vis(n + 1, vector<ll>(m + 1));
    for(ll i = 1; i <= n; i ++ ) {
        string s; cin >> s;
        for(ll j = 1; j <= m; j ++ ) {
            a[i][j] = s[j - 1] - '0';
        }
    } 
    for(ll i = 1; i <= n; i ++ ) {
        for(ll j = 1; j <= m; j ++ ) {
            if(a[i][j] && !vis[i][j]) {
                ans = min(ans, dfs(i, j, 0, vis, a));
                vis[i][j] = 1;
                while(!x00.empty()) {
                    ll x = x00.front(), y = y00.front();
                    vis[x][y] = 0;
                    x00.pop(), y00.pop();
                }
            }
        }
    }
    cout << ans << "\n";
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