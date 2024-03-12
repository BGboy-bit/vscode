#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 1;//∂‡◊È ‰»Î

ll dp[MAX][4];
/*
dp[0]: "" 
dp[1]: "t"
dp[2]: "tx"
dp[3]: "txt"
*/
void init() {
    dp[0][0] = 1;
    for(ll i = 1; i <= MAX; i ++ ) {
        dp[i][0] = (dp[i - 1][0] * 25 + dp[i - 1][1] * 24 + dp[i - 1][2] * 25) % mod;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
        dp[i][2] = dp[i - 1][1];
        dp[i][3] = (dp[i - 1][2] + dp[i - 1][3] * 26) % mod;
    }
}

void Solve() {
    ll n; cin >> n;
    cout << dp[n][3] << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    init();
    ll T = 1;
    if(multi) cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}