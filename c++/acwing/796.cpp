#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 1010;
ll a[MAX][MAX], s[MAX][MAX];
ll n, m, q;
ll x1, y1, x2, y2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> q;
    for(ll i = 1; i <= n; i ++ ) {
        for(ll j = 1; j <= m; j ++ ) {
            cin >> a[i][j];
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        } 
    }
    while(q -- ) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1] << "\n"; 
    }
    return 0;
}