#include <bits/stdc++.h>
// #define int long long
using ll = long long;
using PII = std::array<int, 2>;
using namespace std;
const ll INF = 2E18 + 10;
const int N = 1E5 + 5;
struct DSU {
    std::vector<int> f, siz;
    DSU(int n) : f(n), siz(n, 1) { std::iota(f.begin(), f.end(), 0); }
    int find(int x) {
        while (x != f[x]) x = f[x] = f[f[x]];
        return x;
    }
    bool same(int x, int y) { return find(x) == find(y); }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (size(x) < size(y)) swap(x, y);
        if (x == y) return false;
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    int size(int x) { return siz[find(x)]; }
};

ll d[N];
bool st[N], ex[N];
array<int, 3> edges[N];
unordered_map<int, int> mp[N];

void SINGLE_TEST() {
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++) {
        cin >> edges[i][1] >> edges[i][2] >> edges[i][0];
        edges[i][1]--;
        edges[i][2]--;
        if (edges[i][1] > edges[i][2]) swap(edges[i][1], edges[i][2]);
    }
    sort(edges, edges + m);
    for (int i = 0; i < m; i++) {
        if (!mp[edges[i][1]].count(edges[i][2])) {
            mp[edges[i][1]][edges[i][2]] = i;
        }
    }
    DSU dsu(n);
    for (int i = 0; i < n; i++) d[i] = INF;
    while (q--) {
        int k;
        cin >> k;
        vector<int> v(k);
        for (int i = 0; i < k; i++) {
            cin >> v[i];
            v[i]--;
            ex[v[i]] = 1;
        }
        ll ans = 0;
        int cnt = 0;
        if (k <= 300) {
            sort(v.begin(), v.end());
            vector<int> tmp;
            for (auto v1 : v) {
                int t = -1;
                for (auto v2 : v) {
                    if (mp[v1].count(v2)) {
                        tmp.push_back(mp[v1][v2]);
                    }
                }
            }
            sort(tmp.begin(), tmp.end());
            for (auto i : tmp) {
                if (dsu.merge(edges[i][1], edges[i][2])) {
                    ans += edges[i][0];
                    cnt++;
                }
            }
        } else {
            for (int i = 0; i < m; i++) {
                if (ex[edges[i][1]] && ex[edges[i][2]]) {
                    if (dsu.merge(edges[i][1], edges[i][2])) {
                        ans += edges[i][0];
                        cnt++;
                    }
                }
            }
        }
        if (cnt < k - 1) ans = -1;
        cout << ans << "\n";
        for (auto v1 : v) {
            dsu.f[v1] = v1;
            dsu.siz[v1] = 1;
            ex[v1] = 0;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int SAMPLES = 1;
    // cin>>SAMPLES;
    while (SAMPLES--) SINGLE_TEST();
}
