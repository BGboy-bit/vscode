// P1896 [SCOI2005] 互不侵犯
// https://www.luogu.com.cn/problem/P1896

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[10][100][100];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll n, m; cin >> n >> m;

    vector<pair<ll, ll>> sit;
    ll val = 0, maxx = 1 << n; 
    while(val < maxx) {
        bitset<10> bt(val);
        bool ac = 1;
        for(ll i = 0; i < n - 1; i ++ ) {
            if(bt[i] == 1 && bt[i + 1] == 1) {
                ac = 0; break;
            }
        } 
        if(ac) {
            sit.push_back({val, bt.count()});
        }
        val ++ ;
    }
    ll cnt = sit.size();

    for(ll i = 0; i < cnt; i ++ ) {
        dp[1][i][sit[i].second] = 1;  
    }
    for(ll i = 2; i <= n; i ++ ) {
        for(ll j = 0; j < cnt; j ++ ) {
            for(ll k = 0; k < cnt; k ++ ) {
                if(sit[j].first & sit[k].first || 
                  (sit[j].first << 1) & sit[k].first || 
                  (sit[j].first >> 1) & sit[k].first) continue;
                for(ll mm = m; mm >= sit[j].second; mm -- ) {
                    dp[i][j][mm] += dp[i - 1][k][mm - sit[j].second]; 
                } 
            }
        }
    }
    ll ans = 0;
    for(ll i = 0; i < cnt; i ++ ) ans += dp[n][i][m];
    cout << ans << "\n";
    return 0;
}