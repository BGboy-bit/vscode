// P3390 【模板】矩阵快速幂
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
    ll n, k; cin >> n >> k;
    matrix a(n);
    for(ll i = 0; i < n; i ++ ) {
        for(ll j = 0; j < n; j ++ ) {
            ll x; cin >> x;
            a[i][j] = x;
        }
    }
    auto ans = qpow(a, k);
    for(ll i = 0; i < n; i ++ ) {
        for(ll j = 0; j < n; j ++ ) {
            cout << ans[i][j] << " \n"[j == n - 1];
        }
    }
}