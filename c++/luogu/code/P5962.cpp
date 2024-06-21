#include<bits/stdc++.h>
using namespace std;
typedef int ll;

struct Node {
    ll x, y;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    vector<ll> vv[n + 1], a[n + 1];
    for(ll i = 1; i <= n; i ++ ) {
        string s; cin >> s;
        ll las = 0, bef = 0;
        bool ff = 0;
        for(ll j = 0; j < s.size(); j ++ ) {
            if(s.size() == 1) break;
            if(s[j] <= '9' && s[j] >= '0') {
                las = las * 10 + s[j] - '0';
            } else if((s[j] == ',' || s[j] == ';') && !ff) {
                a[i].push_back(1); 
                vv[i].push_back(las);
                las = 0;
            } else if((s[j] == ',' || s[j] == ';') && ff) {
                for(ll k = bef; k <= las; k ++ ) {
                    a[i].push_back(1);
                    vv[i].push_back(k);
                }
                ff = 0; las = 0;
            } else if(s[j] == '-') {
                ff = 1; bef = las; las = 0;
            }
        }
    }
    // 二分查找
    auto find = [&](ll i, ll w) {
        ll l = 0, r = vv[i].size() - 1;
        while(l <= r) {
            ll mid = l + r >> 1;
            if(vv[i][mid] == w) return mid;
            else if(vv[i][mid] > w) r = mid - 1;
            else l = mid + 1;
        } 
        return -1;
    };
    // bfs
    vector<ll> anss;
    unordered_map<ll, ll> mp;
    queue<Node> q;
    ll xx[] = {0, 0, 1, -1};
    ll yy[] = {1, -1, 0, 0};
    auto bfs = [&](Node u) {
        while (!q.empty()) q.pop();
        q.push(u);
        a[u.x][u.y] = 0;
        ll ans = 1;
        while(!q.empty()) {
            u = q.front();
            q.pop();
            ll x = u.x, y = u.y;
            for(ll i = 0; i <= 3; i ++ ) {
                ll x1 = x + xx[i], y1 = y + yy[i];
                // 左右搜
                if(i <= 1) {
                    if(y1 >= 0 && y1 < vv[x1].size()) {
                        if(a[x1][y1] == 1 && (vv[x1][y1] == vv[x][y] + 1 || vv[x1][y1] == vv[x][y] - 1)) {
                            a[x1][y1] = 0;
                            Node v; v.x = x1; v.y = y1;
                            q.push(v);
                            ans ++ ;
                            // cout << v.x << " " << vv[v.x][v.y] << "\n"; 
                        }
                    }
                } else { // 上下搜
                    if(x1 <= 0 || x1 > n) continue;
                    ll w = vv[x][y1];
                    ll to = find(x1, w);
                    if(to != -1 && a[x1][to] == 1) {
                        a[x1][to] = 0;
                        Node v; v.x = x1; v.y = to;
                        q.push(v);
                        ans ++ ;
                        // cout << v.x << " " << vv[v.x][v.y] << "\n"; 
                    }
                }
            }
        }
        if(mp[ans] == 0) anss.push_back(ans);
        mp[ans] ++ ;
    };

    for(ll i = 1; i <= n; i ++ ) { 
        for(ll j = 0; j < vv[i].size(); j ++ ) {
            if(a[i][j] == 1) {
                Node u;
                u.x = i; u.y = j;
                bfs(u); 
            } 
        }
    }
    sort(anss.begin(), anss.end(), greater<ll>());
    for(auto i : anss) {
        cout << i << " " << mp[i] << "\n"; 
    }
}