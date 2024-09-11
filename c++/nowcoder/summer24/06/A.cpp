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
bool multi = 1;

struct node {
    ll u, ze, on;
};

void dfs(ll x, ll fa, vector<vector<PII>> &e, ll ff, vector<db> &ans, ll las) {
    db anss = 0;
    for(auto p : e[x]) {
        ll y = p[0], k = p[1];
        if(y == fa) continue;
        ll f = ff ^ 1;
        dfs(y, x, e, f, ans, k);
        if(ff) {
            if(anss == 0) anss = ans[y];
            else anss = max(anss, ans[y]);
        } else {
            if(anss == 0) anss = ans[y];
            anss = min(anss, ans[y]);
        }
    }
    if(anss == 0) return ;
    if(!las) {
        if(anss < ans[x]) ans[x] = anss;
    } else {
        ans[x] = anss;
    }
}

void Solve() {
    ll n; cin >> n;
    vector<vector<PII>> e(n + 1);
    vector<db> ans(n + 1);
    vector<bool> vis(n + 1);
    for(ll i = 1; i < n; i ++ ) {
        ll x, y, k; cin >> x >> y >> k;
        e[x].push_back({y, k});
        e[y].push_back({x, k});
    }

    queue<node> q;
    q.push((node){1, 0, 0});
    while(!q.empty()) {
        node d = q.front(); q.pop();
        ll u = d.u, ze = d.ze, on = d.on;
        for(auto p : e[u]) {
            ll v = p[0], k = p[1];
            if(vis[v] == true) continue;
            else vis[v] = true;
            if(k == 1) {
                ans[v] = (db)(on + 1) / (db)(on + ze + 1); 
                q.push((node){v, ze, on + 1});
            }
            else {
                ans[v] = (db)on / (db)(on + ze + 1); 
                q.push((node){v, ze + 1, on});
            }
        }
    }
    dfs(1, 1, e, 1, ans, 0);
    db anss = 0;
    for(auto p : e[1]) {
        anss = max(ans[p[0]], anss);
    }
    cout << fixed << setprecision(10);
    cout << anss << "\n";
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