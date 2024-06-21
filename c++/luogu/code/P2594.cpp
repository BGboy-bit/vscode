#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n, m; cin >> n >> m;
    vector<vector<ll>> s(n + 1, vector<ll>(m + 1, 0)), v(n + 1, vector<ll>(m + 1, 0));
    for(ll i = 1; i <= n; i ++ ) {
        for(ll j = 1; j <= m; j ++ ) {
            char c; cin >> c;
            if(c == 'T') s[i][j] = 1;
        }
    }
    ll ans = 0, ff = 0, maxx, maxy;
    function<void(ll, ll)> dfs = [&](ll x, ll y) {
        if(s[x][y] == 0) return ;
        else s[x][y] = 0;
        ll xx[] = {1, -1, 0, 0};
        ll yy[] = {0 , 0, -1, 1};
        for(ll i = 0; i < 4; i ++ ) {
            ll x1 = x + xx[i]; ll y1 = y + yy[i];
            if(x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= m) {
                if(s[x1][y1] == 1) {
                    // cout << x1 << " " << y1 << "\n";
                    // cout << "maxx = " << maxx << " maxy = " << maxy << "\n"; 
                    if(x1 >= maxx) {
                        maxx = x1;
                        if(y1 == maxy) ff = 1;
                        else ff = 0; 
                    }
                    if(y1 >= maxy) {
                        maxy = y1;
                        if(x1 == maxx) ff = 1;
                        else ff = 0;
                    }
                    dfs(x1, y1);
                }
            }
        }
    };
    for(ll i = 1; i <= n; i ++ ) {
        for(ll j = 1; j <= m; j ++ ) {
            if(s[i][j] == 1) {
                ff = 1; maxx = i; maxy = j; 
                dfs(i, j);
                ans += ff;
            }
        }
    }
    if(ans % 2 == 0) cout << "=_=\n";
    else cout << "-_-\n";  
 }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T; cin >> T;
    while(T -- ) {
        Solve();
    }
}