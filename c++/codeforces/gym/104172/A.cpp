#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
using PII = pair<int, int>;

constexpr ll INF = 2E18 + 10;
constexpr int N = 2E6 + 10;

int p[N];
vector <int>g[N];

int dfs(int u) {
	if(g[u].size() == 0) return 1;
	if(g[u].size() == 1) return dfs(g[u].front());
    vector<ll> a;
    for(auto v : g[u]) {
        a.push_back(dfs(v));
    }
    sort(a.begin(), a.end());
    return max(a.back(), a[a.size() - 2] + 1);
}

void solve() {
    int n;
    cin >> n;
    for(int i = 1;i <= n; i ++ ) {
        cin >> p[i];
        g[i].clear();
    }
    for(int i = 2; i <= n; i ++ ) g[p[i]].push_back(i);
    cout << dfs(1) <<'\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while(T -- ) {
        solve();
    }
}