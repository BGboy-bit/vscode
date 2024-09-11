#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 1e3 + 10;
ll n;
ll a[MAX];
bool graph[MAX][MAX];
bool vis[MAX];
ll ans;

ll dfs(ll pos) {
    ll sum = a[pos];
    vis[pos] = 1;
    for(ll i = 1; i <= n; i ++ ) {
        if(!vis[i] && graph[pos][i]) {
            sum = max(sum, sum + dfs(i));
        }
    }
    //保证查了子图
    ans = max(ans, sum);
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(ll i = 1; i <= n; i ++ ) cin >> a[i];
    ll x, y;
    for(ll i = 1; i < n; i++ ) {
        cin >> x >> y;
        graph[x][y] = 1;
        graph[y][x] = 1;
    }
    dfs(1);
    cout << ans << "\n";
    return 0;
}