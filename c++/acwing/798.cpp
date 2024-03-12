#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 1e3 + 10;
ll n, m, q;
ll graph[MAX][MAX];

void insert(ll x1, ll y1, ll x2, ll y2, ll c) {
    graph[x1][y1] += c;
    graph[x1][y2 + 1] -= c;
    graph[x2 + 1][y1] -= c;
    graph[x2 + 1][y2 + 1] += c;     
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> q;
    for(ll i = 1; i <= n; i ++ ) {
        for(ll j = 1; j <= m; j ++ ) {
            ll c;
            cin >> c;
            insert(i, j, i, j, c);
        }
    }
    while(q --) {
        ll x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        insert(x1, y1, x2, y2, c);
    }
    for(ll i = 1; i <= n; i ++ ) {
        for(ll j = 1; j <= m; j ++ ) {
            graph[i][j] += graph[i - 1][j] + graph[i][j - 1] - graph[i - 1][j - 1];
            cout << graph[i][j] << " ";
        } 
        cout << "\n";
    } 
    return 0;
}