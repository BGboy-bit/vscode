#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 1e6 + 10;

ll n;
ll a[MAX], b[MAX];
ll dp[MAX][3];//1左移，2不动，3右移
void Solve() {
    cin >> n;
    for(ll i = 1; i <= n; i ++ ) cin >> a[i];
    for(ll i = 1; i <= n; i ++ ) cin >> b[i];

    for(ll i = 1; i <= n; i ++ ) {
        if(b[i] == 1) {//有盖子
            dp[i][0] = dp[i - 1][0] + a[i - 1];//左移盖子的最大值即为左边箱子上没有盖子
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + a[i];//盖子不动的最大值即为左边盖子没有右移
            dp[i][2] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2])) + a[i + 1];//盖子右移后自己上面空出来了，就要对左边的盖子的三种情况取最大值
        } else {//没有盖子
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);//保证自己上面没有盖子
            dp[i][1] = dp[i][2] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));//上一种状态取最大值
        }
    }
    cout << max(dp[n][0], dp[n][1]) << "\n";//最后一个盖子只能左移或不移
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    // cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}