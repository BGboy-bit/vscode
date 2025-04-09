#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

ll count_bit_ones(ll l, ll r, int k) {
    ll len = 1LL << (k + 1);
    ll full = (r + 1) / len * (1LL << k);
    ll rem = max(0LL, (r + 1) % len - (1LL << k));
    ll cnt_r = full + rem;

    l--;
    full = (l + 1) / len * (1LL << k);
    rem = max(0LL, (l + 1) % len - (1LL << k));
    ll cnt_l = full + rem;

    return cnt_r - cnt_l;
}

ll qpow(ll a, ll b, ll m) {
    ll res = 1;
    while(b) {
        if(b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void Solve() {
    int T;
    cin >> T;
    while(T--) {
        ll l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        ll len1 = r1 - l1 + 1, len2 = r2 - l2 + 1;
        ll total = len1 * len2 % mod;

        ll ans = 0;
        for(int k = 0; k < 32; k++) {
            ll a1 = count_bit_ones(l1, r1, k);
            ll a0 = len1 - a1;
            ll b1 = count_bit_ones(l2, r2, k);
            ll b0 = len2 - b1;

            ll cnt = (a0 * b1 % mod + a1 * b0 % mod) % mod;
            ans = (ans + cnt * ((1LL << k) % mod) % mod) % mod;
        }

        ll inv = qpow(total, mod - 2, mod);
        cout << ans * inv % mod << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    Solve();
    return 0;
}
