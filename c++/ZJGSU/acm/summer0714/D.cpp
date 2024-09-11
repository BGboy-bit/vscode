#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int MAX = 210;
ll n;
ll graph[MAX][MAX];
ll a[MAX];
bool vis[MAX];

bool Prime(ll i, ll j) {
    ll x = a[i] + a[j];
    if(x == 2) return true;
    for(ll i = 2; i * i <= x; i ++ ) {
        if(x % i == 0) return false;
    }
    return true;
}

bool dfs(ll fro, ll dis, bool ff, ll cnt) {
    for(ll i = 1; i <= n; i ++ ) {
        if(graph[fro][i] == 1) {
            if(i == dis && cnt >= 2) {
                ff = 1;
                return true;
            }
            else if(!vis[i]) {
                vis[i] = 1;
                if(dfs(i, dis, ff, cnt + 1)) return true;
                vis[i] = 0;
            }
        }    
    } 
    return false;
}

bool dfs1() {
    for(ll j = 1; j <= n; j ++ ) {
        if(!vis[j]) {
            vis[j] = 1;
            for(ll i = 1; i <= n; i ++ ) {
                if(graph[1][i] == 1) {
                    vis[i] = 1;
                    if(dfs(i, 1, 0, 1)) dfs1();
                    else vis[i] = 0;
                }
                bool ff = 1;
                for(ll i = 1; i <= n; i ++ ) {
                    if(!vis[i]) ff = 0;
                }
                if(ff) break;
            }
        }
    }
    for(ll i = 1; i <= n; i ++ ) {
        if(vis[i] == 0) return false; 
    }
    return true;
}

void Solve() {
    cin >> n;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
    }
    for(ll i = 1; i < n; i ++ ) {
        for(ll j = i + 1; j <= n; j ++ ) {
            if(Prime(i, j)) {
                graph[i][j] = 1;
                graph[j][i] = 1;
            }
        }
    }
    if(dfs1()) cout << "Yes" << "\n";
    else cout << "No" << "\n";
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