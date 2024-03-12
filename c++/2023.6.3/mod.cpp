/*
½×³ËÇóÓà
http://10.21.15.91/contest/1018/problem/B
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 998244353;
const int MAX = 5e5 + 10;
ll n, x;
ll cnt[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> x;
    for(ll i = 1; i <= n; i ++ ) {
        ll a;
        cin >> a;
        cnt[a] ++;
    }   
    ll ans = 0, res = 1; 
    for(ll i = 1; i < x; i ++ ) {
        res = res * i % MOD;
        cnt[i + 1] += cnt[i] / (i + 1);
        cnt[i] %= i + 1;
        ans = (ans + cnt[i] * res % MOD) % MOD;       
    }
    cout << ans << "\n";
    return 0;
}