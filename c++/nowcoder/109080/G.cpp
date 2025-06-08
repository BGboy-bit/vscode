#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;

template<typename T = ll>
struct matrix {
    int n;
    std::vector<std::vector<T>> a;
    matrix(int _n) : n(_n), a(_n, std::vector<T>(_n, 0)) {}

    matrix operator*(matrix<T>& b) {
        matrix<T> res{n};
        for (int i = 0; i < n; ++i)
            for (int k = 0; k < n; ++k) if (a[i][k])
                for (int j = 0; j < n; ++j)
                    res[i][j] = (res[i][j] + a[i][k] * b[k][j] % mod) % mod;
        return res;
    }
    matrix operator*(matrix<T>&& b) { return (*this) * b; }
    std::vector<T>& operator[](int y) { return a[y]; }
};

template<typename T = ll>
T qpow(T a, ll b) {           
    T res{a.n};
    for (int i = 0; i < a.n; ++i) res[i][i] = 1;
    while (b) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    vector<ll> a(n + 1);
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
    }
    ll c, m, k, t; cin >> c >> m >> k >> t;
    c %= m;
    vector<ll> dp(m);
    for(ll i = 1; i <= n; i ++ ) {
        a[i] %= m;
        vector<ll> dp2(m);
        dp2[a[i]] = 1;
        for(ll j = 0; j < m; j ++ ) {
            dp2[(a[i] + j) % m] = (dp2[(a[i] + j) % m] + dp[j]) % mod;
        }
        for(ll j = 0; j < m; j ++ ) {
            dp[j] = (dp2[j] + dp[j]) % mod;
        }
    }
    matrix p(m);
    for(ll i = 0; i < m; i ++ ) {
        for(ll j = 0; j < m; j ++ ) {
            p[j][i * j % m] = (p[j][i * j % m] + dp[i]) % mod;
        } 
    }   
    matrix q(m);
    q[c][c] = 1;
    auto res = q * qpow(p, t);
    cout << res[c][k] << "\n";
    return 0;
}