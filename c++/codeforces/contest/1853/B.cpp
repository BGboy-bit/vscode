#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;

ll n, k;
ll cnt;

void dfs(ll x, ll y, ll res) {
    if(res == k) cnt ++ ;
    else if(x - y <= y) dfs(y, x - y, res + 1);
}
 
void Solve() {
    cin >> n >> k;
    cnt = 0;
    if(k == 3) {
        cout << n / 2 + 1 << "\n"; return ;
    }
    for(ll i = (n + 1) / 2; i <= n * 2 / 3; i ++ ) dfs(n, i, 2);
    cout << cnt << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}