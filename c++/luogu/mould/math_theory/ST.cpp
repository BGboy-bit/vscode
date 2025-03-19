// P3865 【模板】ST 表
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll n, m; cin >> n >> m;
    // 构造对数数组
    vector<ll> lg(n + 1);
    lg[1] = 0;
    for(ll i = 2; i <= n; i ++ ) {
        lg[i] = lg[i >> 1] + 1;
    }
    // 构造st数组
    vector<vector<ll>> st(n + 1, vector<ll>(20));
    for(ll i = 1; i <= n; i ++ ) {
        cin >> st[i][0];
    }
    for(ll j = 1; j <= lg[n]; j ++ ) {
        for(ll i = 1; i <= n - (1 << j) + 1; i ++ ) {
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    for(ll i = 1; i <= m; i ++ ) {
        ll l, r; cin >> l >> r;
        ll k = lg[r - l + 1]; // (L + 2^k − 1 <= R) ⇔ (k <= lg[R − L + 1])
        ll d = r - (1 << k) + 1; // (D + 2^k − 1 = R) ⇔ (D = R − 2^k + 1)
        cout << max(st[l][k], st[d][k]) << "\n";
    }
    return 0;
}