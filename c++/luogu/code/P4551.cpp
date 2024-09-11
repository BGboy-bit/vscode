// P4551 最长异或路径
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 10; 
vector<pair<ll, ll>> e[N]; 
ll dis[N];                    // 表示从 X 到根节点的边权异或和
ll trie[N << 4][2], cnt = 1;  //字典树
bool exist[N << 4];           //结束标识

void dfs(ll u, ll fa) {       // 求dis数组
    for(auto i : e[u]) {
        ll v = i.first;
        ll w = i.second;
        if(v == fa) continue;
        dis[v] = (w ^ dis[u]);
        dfs(v, u);
    }
}

void insert(ll x) {
    ll pos = 1;
    for(ll i = 31; i >= 0; i -- ) {
        ll b2 = ((x >> i) & 1);
        if(!trie[pos][b2]) 
            trie[pos][b2] = ++ cnt;
        pos = trie[pos][b2];
    }
    exist[pos] = 1;
}

ll find(ll x) {
    ll pos = 1;
    ll sum = 0;
    for(ll i = 31; i >= 0; i -- ) {
        ll b2 = ((x >> i) & 1);
        if(trie[pos][b2 ^ 1]) {
            sum += 1 << i;
            pos = trie[pos][b2 ^ 1]; 
        } else {
            pos = trie[pos][b2];
        }
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    for(ll i = 1; i < n; i ++ ) {
        ll u, v, w; cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    dis[1] = 0;
    dfs(1, 0);
    for(ll i = 1; i <= n; i ++ ) insert(dis[i]);
    ll ans = 0;
    for(ll i = 1; i <= n; i ++ ){
        ans = max(ans, find(dis[i]));
    }
    cout << ans << "\n";
    return 0;
}