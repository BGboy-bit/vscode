#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll =long long;

struct Node  {
    ll x, y;
};


int n, m;
vector<vector<ll>> cnt(1010, vector<ll> (1010, 0));
vector<vector<char>> a(1010, vector<char>(1010));
int cnt1, cnt2, cnt3; 

void ac(int u, int v) {
    ll ans = 0;
    queue<Node> q;
    queue<Node> le;
    q.push({u, v});
    while(!q.empty()) {
        Node d = q.front(); q.pop();
        int x = d.x, y = d.y;
        cnt[x][y] ++ ;
        if(a[x][y + 1] == '#' && a[x + 1][y] == '#' && a[x + 1][y + 1] == '.') {
            le.push({x, y});
        } 
        if(cnt[x][y] == 2 && !le.empty()) {
            Node d1 = le.front();
            if(x > d1.x && y > d1.y) {
                ans ++ ;
                le.pop();
            }   
        }
        if(a[x][y + 1] == '#') q.push({x, y + 1});
        if(a[x + 1][y] == '#') q.push({x + 1, y});
    }
    if(ans == 0) cnt1 ++ ;
    if(ans == 1) cnt2 ++ ;
    if(ans == 2) cnt3 ++ ;
}

void solve() {
    cin>>n>>m;
    for(int i = 1; i <= n; i ++ ) {
        for(int j = 1; j <= m; j ++ ) {
            cin >> a[i][j];
        }
    }
    for(ll i = 1; i <= n; i ++ ) {
        for(ll j = 1; j <= m; j ++ ) {
            if(cnt[i][j] == 0 && a[i][j] == '#') {
                ac(i, j);
            }
        }
    }
    cout << cnt1 << " " << cnt2 << " " << cnt3 << "\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
}