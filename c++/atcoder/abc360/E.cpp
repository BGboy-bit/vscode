#include <bits/stdc++.h>
#define int long long
using ll = int;
using PII = std::array<int, 2>;
using namespace std;
const ll INF = 2e18 + 10;
#ifdef __clang__
    template <typename T>
    inline int my_lg(T n) {return (n > 0) ? static_cast<int>(log2(n)) : -1;}
    #define __lg my_lg
    #define __gcd gcd
#endif
// struct cmp{bool operator()(const int & x, const int &y) const{ return x<y;}};
const int N = 2E6 + 10;
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
struct Mint {
    int x;
    constexpr Mint() : x{} {}
    constexpr Mint(ll x) : x{norm(x % getMod())} {}

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
    constexpr Mint operator-() const {
        Mint res;
        res.x = norm(getMod() - x);
        return res;
    }
    constexpr Mint inv() const {
        assert(x != 0);
        return power(*this, getMod() - 2);
    }
    constexpr Mint &operator*=(Mint rhs) & {
        x = 1LL * x * rhs.x % getMod();
        return *this;
    }
    constexpr Mint &operator+=(Mint rhs) & {
        x = norm(x + rhs.x);
        return *this;
    }
    constexpr Mint &operator-=(Mint rhs) & {
        x = norm(x - rhs.x);
        return *this;
    }
    constexpr Mint &operator/=(Mint rhs) & { return *this *= rhs.inv(); }
    friend constexpr Mint operator*(Mint lhs, Mint rhs) {
        Mint res = lhs;
        res *= rhs;
        return res;
    }
    friend constexpr Mint operator+(Mint lhs, Mint rhs) {
        Mint res = lhs;
        res += rhs;
        return res;
    }
    friend constexpr Mint operator-(Mint lhs, Mint rhs) {
        Mint res = lhs;
        res -= rhs;
        return res;
    }
    friend constexpr Mint operator/(Mint lhs, Mint rhs) {
        Mint res = lhs;
        res /= rhs;
        return res;
    }
    friend constexpr std::istream &operator>>(std::istream &is, Mint &a) {
        ll v;
        is >> v;
        a = Mint(v);
        return is;
    }
    friend constexpr std::ostream &operator<<(std::ostream &os, const Mint &a) {
        return os << a.val();
    }
    friend constexpr bool operator==(Mint lhs, Mint rhs) {
        return lhs.val() == rhs.val();
    }
    friend constexpr bool operator!=(Mint lhs, Mint rhs) {
        return lhs.val() != rhs.val();
    }
};

template <>
// int Mint<0>::Mod = 1e9+7;
int Mint<0>::Mod = 998244353;

template <int V, int P>
constexpr Mint<P> CInv = Mint<P>(V).inv();

// constexpr int P = 1e9+7;
constexpr int P = 998244353;
using Z = Mint<P>;

void SINGLE_TEST() 
{
    ll n, k; cin >> n >> k;
    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int SAMPLES = 1;
    cin >> SAMPLES;
    for(int CUR=1;CUR<=SAMPLES;CUR++){
        SINGLE_TEST();
    }
}
