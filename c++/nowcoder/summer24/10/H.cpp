#include <bits/stdc++.h>
// #define int long long
// using int = long long;
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
using PII = std::array<int, 2>;
using namespace std;
// const int INF = 2E18 + 10;
#define inr(ITEM, a, b) (a <= ITEM && ITEM <= b)

template <class T>
constexpr T power(T a, int b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}

constexpr int mul(int a, int b, int p) {
    int res = a * b - int(1.L * a * b / p) * p;
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
    constexpr MInt(int x) : x{norm(x % getMod())} {}

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
        x = 1ll * x * rhs.x % getMod();
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
        int v;
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
const int N = 2E6 + 10;

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
    int a, b; 
    cin >> a >> b; 
    // a = rng() % 998244353 + 1; b = rng() % 998244353 + 1;
    // cout << a << " " << b << "\n";
    // if(a + b >= 998244353) return;
    if(a == b) {
        cout << (Z)1 / (Z)2 << " " << (Z)1 / (Z)2 << "\n";
        return ;
    }
    Z pa = 0, pb = 0;
    Z cnt = 1;
    map<pair<int , int>, int> mp;
    vector<pair<int, int>> pp;
    // pp.push_back({a, b});
    // mp[{a, b}] = 1;

    bool ff = 0;
    int cntt = 0;
    vector<int> ct;

    while(a != b) {
        if(a < b) {
            cnt *= (Z)2;
            pb += (Z)1 / (Z)cnt;
            b -= a;
            a *= 2;
        } else {
            cnt *= 2;
            pa += (Z)1 / (Z)cnt;
            a -= b;
            b *= 2;
        }
        pp.push_back({a, b});
        if(!mp.count({a, b})) {
            mp[{a, b}] = 1;
            // mp[{b, a}] = 1;
        } else break;

        if(a > b) {
            if(ff) cntt ++ ;
            else {
                ct.push_back(cntt);
                cntt = 1;
                ff = 1;
            } 
        } else {
            if(!ff) cntt -- ;
            else {
                ct.push_back(cntt);
                cntt = -1;
                ff = 0;
            } 
        }

        cout << a << " " << b << "\n";
    }
    reverse(pp.begin(), pp.end());
    pair<int, int> p1 = pp[0]; 
    vector<int> ans;
    if(pp.size() == 1) {
        pa += (Z)1 / (Z)cnt * (Z)1 / (Z)2;
        pb += (Z)1 / (Z)cnt * (Z)1 / (Z)2;
        cout << pa << " " << pb << "\n";
        return ;
    } else {
        for(auto i = 1; i < pp.size(); i ++ ) {
            if(pp[i].first > pp[i].second) {
                ans.push_back(1);
            } else {
                ans.push_back(0);
            }
            if(pp[i] == pp[0]) break;
        }
    }
    // reverse(ans.begin(), ans.end());
    Z x = 1, y = 1;
    for(int i = 1; i <= ans.size(); i ++ ) y *= (Z)2;
    y -= (Z)1;
    for(int i = 0; i < ans.size(); i ++ ) {
        if(ans[i] == 1) {
            pa += (Z)1 / (Z)cnt * x / y;
        } else {
            pb += (Z)1 / (Z)cnt * x / y;    
        }
        x *= (Z)2;
    }
    cout << pa << " " << pb << "\n";
    for(int i = 0; i < ct.size(); i ++ ) cout << ct[i] << " \n"[i == ct.size() - 1];
}

signed main() {
    // cin.tie(nullptr)->sync_with_stdio(false);
    // INIT();
    int SAMPLES = 1;
    // cin >> SAMPLES;
    while (SAMPLES--) SINGLE_TEST();
}