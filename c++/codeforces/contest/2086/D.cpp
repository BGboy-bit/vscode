#include <bits/stdc++.h>
#define int long long
using ll = long long;
using PII = std::array<int, 2>;
using namespace std;
const ll INF = 2E18 + 10;
#define inr(ITEM, a, b) (a <= ITEM && ITEM <= b)

template <class T>
constexpr T power(T a, ll b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}

constexpr ll mul(ll a, ll b, ll p) {
    ll res = a * b - ll(1.L * a * b / p) * p;
    res %= p;
    if (res < 0) {
        res += p;
    }
    return res;
}

template <int P>
struct MInt {
    int x;
    constexpr MInt() : x{} {}
    constexpr MInt(ll x) : x{norm(x % getMod())} {}

    static int Mod;
    constexpr static int getMod() {
        if (P > 0) {
            return P;
        } else {
            return Mod;
        }
    }
    constexpr static void setMod(int Mod_) { Mod = Mod_; }
    constexpr int norm(int x) const {
        if (x < 0) {
            x += getMod();
        }
        if (x >= getMod()) {
            x -= getMod();
        }
        return x;
    }
    constexpr int val() const { return x; }
    explicit constexpr operator int() const { return x; }
    constexpr MInt operator-() const {
        MInt res;
        res.x = norm(getMod() - x);
        return res;
    }
    constexpr MInt inv() const {
        assert(x != 0);
        return power(*this, getMod() - 2);
    }
    constexpr MInt &operator*=(MInt rhs) & {
        x = 1LL * x * rhs.x % getMod();
        return *this;
    }
    constexpr MInt &operator+=(MInt rhs) & {
        x = norm(x + rhs.x);
        return *this;
    }
    constexpr MInt &operator-=(MInt rhs) & {
        x = norm(x - rhs.x);
        return *this;
    }
    constexpr MInt &operator/=(MInt rhs) & { return *this *= rhs.inv(); }
    friend constexpr MInt operator*(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res *= rhs;
        return res;
    }
    friend constexpr MInt operator+(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res += rhs;
        return res;
    }
    friend constexpr MInt operator-(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res -= rhs;
        return res;
    }
    friend constexpr MInt operator/(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res /= rhs;
        return res;
    }
    friend constexpr std::istream &operator>>(std::istream &is, MInt &a) {
        ll v;
        is >> v;
        a = MInt(v);
        return is;
    }
    friend constexpr std::ostream &operator<<(std::ostream &os, const MInt &a) {
        return os << a.val();
    }
    friend constexpr bool operator==(MInt lhs, MInt rhs) {
        return lhs.val() == rhs.val();
    }
    friend constexpr bool operator!=(MInt lhs, MInt rhs) {
        return lhs.val() != rhs.val();
    }
};

template <>
// int MInt<0>::Mod = 1e9+7;
int MInt<0>::Mod = 998244353;

template <int V, int P>
constexpr MInt<P> CInv = MInt<P>(V).inv();

// constexpr int P = 1e9+7;
constexpr int P = 998244353;
using Z = MInt<P>;

// struct cmp{bool operator()(const int & x, const int &y) const{ return x<y;
// }};
const int N = 5E5 + 10;

Z fac[N], invfac[N];

void INIT() {
    fac[0] = invfac[0] = 1;
    for (int i = 1; i < N; i++) fac[i] = fac[i - 1] * i;
    invfac[N - 1] = fac[N - 1].inv();
    for (int i = N - 2; i; i--) invfac[i] = invfac[i + 1] * (i + 1);
}
inline Z A(int a, int b) {
    if (a < 0 || b < 0 || a < b) return 0;
    return fac[a] * invfac[a - b];
}
inline Z C(int a, int b) {
    if (a < 0 || b < 0 || a < b) return 0;
    return fac[a] * invfac[b] * invfac[a - b];
}

void SINGLE_TEST() {
    vector<ll> a; a.push_back(0);
    ll sum = 0;
    for(ll i = 1; i <= 26; i ++ ) {
        ll x; cin >> x; sum += x;
        if(x > 0) a.push_back(x);
    }
    ll sum1 = sum / 2;
    ll n = a.size() - 1; 
    vector<vector<Z>> dp(n + 1, vector<Z> (sum1 + 1));
    dp[0][0] = 1;
    for(ll i = 1; i <= n; i ++ ) {
        for(ll j = 0; j <= sum1; j ++ ) {
            
        }
        for(ll j = 0; j <= sum1; j ++ ) {
            dp[i][j] = dp[i - 1][j];
            if(j - a[i] >= 0) 
                dp[i][j] += dp[i - 1][j - a[i]];
        }
    }
    // vector<Z> dp(sum + 1);
    // dp[0] = 1;
    // for(ll i = 1; i <= n; i ++ ) {
    //     for(ll j = sum1; j >= a[i]; j -- ) {
    //        dp[j] = dp[j] + dp[j - a[i]]; 
    //     }
    // }
    Z ans = A(sum / 2, sum / 2) * A((sum + 1) / 2, (sum + 1) / 2) * dp[n][sum1];
    for(auto i : a) {
        Z x = A(i, i);
        ans = ans / A(i, i);
    }
    cout << ans << "\n";
}   

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    INIT();
    int SAMPLES = 1;
    cin >> SAMPLES;
    while (SAMPLES--) SINGLE_TEST();
}

