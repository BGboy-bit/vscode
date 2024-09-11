#include <bits/stdc++.h>
#define int long long
using ll = long long;
using PII = std::array<int, 2>;
using namespace std;
const ll INF = 2E18 + 10;
#ifdef __clang__
template <typename T>
inline int my_lg(T n) {
    return (n > 0) ? static_cast<int>(log2(n)) : -1;
}
#define __lg my_lg
#define __gcd gcd
#endif
#ifndef ONLINE_JUDGE
#define EL std::cout << "\n";
#define COUT(ITEM) std::cout << #ITEM << "=" << ITEM << '\n';
#define CERR(ITEM) std::cerr << #ITEM << "=" << ITEM << '\n';
#endif
// struct cmp{bool operator()(const int & x, const int &y) const{ return x<y;
// }};
const int MAXN = 2010;
ll comb[MAXN][MAXN];
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

struct Segtree {
    int cover;
    int length;
    int max_length;
};

class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        int n = rectangles.size();
        for (const auto& rect: rectangles) {
            // 下边界
            hbound.push_back(rect[1]);
            // 上边界
            hbound.push_back(rect[3]);
        }
        sort(hbound.begin(), hbound.end());
        hbound.erase(unique(hbound.begin(), hbound.end()), hbound.end());
        int m = hbound.size();
        // 线段树有 m-1 个叶子节点，对应着 m-1 个会被完整覆盖的线段，需要开辟 ~4m 大小的空间
        tree.resize(m * 4 + 1);
        init(1, 1, m - 1);

        vector<tuple<int, int, int>> sweep;
        for (int i = 0; i < n; ++i) {
            // 左边界
            sweep.emplace_back(rectangles[i][0], i, 1);
            // 右边界
            sweep.emplace_back(rectangles[i][2], i, -1);
        }
        sort(sweep.begin(), sweep.end());

        long long ans = 0;
        for (int i = 0; i < sweep.size(); ++i) {
            int j = i;
            while (j + 1 < sweep.size() && get<0>(sweep[i]) == get<0>(sweep[j + 1])) {
                ++j;
            }
            if (j + 1 == sweep.size()) {
                break;
            }
            // 一次性地处理掉一批横坐标相同的左右边界
            for (int k = i; k <= j; ++k) {
                auto&& [_, idx, diff] = sweep[k];
                // 使用二分查找得到完整覆盖的线段的编号范围
                int left = lower_bound(hbound.begin(), hbound.end(), rectangles[idx][1]) - hbound.begin() + 1;
                int right = lower_bound(hbound.begin(), hbound.end(), rectangles[idx][3]) - hbound.begin();
                update(1, 1, m - 1, left, right, diff);
            }
            ans += static_cast<long long>(tree[1].length) * (get<0>(sweep[j + 1]) - get<0>(sweep[j]));
            i = j;
        }
        return ans % static_cast<int>(1e9 + 7);
    }

    void init(int idx, int l, int r) {
        tree[idx].cover = tree[idx].length = 0;
        if (l == r) {
            tree[idx].max_length = hbound[l] - hbound[l - 1];
            return;
        }
        int mid = (l + r) / 2;
        init(idx * 2, l, mid);
        init(idx * 2 + 1, mid + 1, r);
        tree[idx].max_length = tree[idx * 2].max_length + tree[idx * 2 + 1].max_length;
    }

    void update(int idx, int l, int r, int ul, int ur, int diff) {
        if (l > ur || r < ul) {
            return;
        }
        if (ul <= l && r <= ur) {
            tree[idx].cover += diff;
            pushup(idx, l, r);
            return;
        }
        int mid = (l + r) / 2;
        update(idx * 2, l, mid, ul, ur, diff);
        update(idx * 2 + 1, mid + 1, r, ul, ur, diff);
        pushup(idx, l, r);
    }

    void pushup(int idx, int l, int r) {
        if (tree[idx].cover > 0) {
            tree[idx].length = tree[idx].max_length;
        }
        else if (l == r) {
            tree[idx].length = 0;
        }
        else {
            tree[idx].length = tree[idx * 2].length + tree[idx * 2 + 1].length;
        }
    }

private:
    vector<Segtree> tree;
    vector<int> hbound;
};
// 计算组合数，取模
void calculate_combinations() {
    for (int n = 0; n <= MAXN; ++n) {
        for (int k = 0; k <= n; ++k) {
            if (k == 0 || k == n) {
                comb[n][k] = 1; // C(n, 0) = C(n, n) = 1
            } else {
                comb[n][k] = (comb[n - 1][k - 1] + comb[n - 1][k]) % P; // 递推关系式，取模
            }
        }
    }
}
 
// 查询组合数，取模
int get_combination(int n, int k) {
    if (k > n || k < 0) {
        return 0; // 如果 k 超过 n 或者小于 0，则返回 0
    }
    return comb[n][k];
}

// // Helper function to recursively find combinations
// void findCombinations(int n, int k, int start, vector<int>& current, vector<vector<int>>& result) {
//     if (current.size() == k) {
//         // 当前组合已满 k 个元素，添加到结果中
//         result.push_back(current);
//         return;
//     }

//     for (int i = start; i <= n; ++i) {
//         current.push_back(i);
//         findCombinations(n, k, i + 1, current, result);
//         current.pop_back(); // 回溯
//     }
// }

// // Function to generate all combinations of k numbers out of 1...n
// vector<vector<int>> generateCombinations(int n, int k) {
//     vector<vector<int>> result;
//     vector<int> current;
//     findCombinations(n, k, 1, current, result);
//     return result;
// }

void SINGLE_TEST() {
    ll n; cin >> n;
    vector<vector<int>> rec(n, vector<int>(4));
    for(ll i = 1; i <= n; i ++ ) {
        ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        rec[i - 1] = {x1, y1, x2, y2};
    }   
    Solution sol;
    for(ll i = 1; i <= n; i ++ ) {
        Z ans = 0;
        vector<vector<int>> rec1(i, vector<int>(4));
        // vector<vector<int>> combinations = generateCombinations(n, i);      
        vector<int> a(i);
        iota(a.begin(), a.end(), 0);
        vector<int> as;
        while(a.front() < n - i - 1) {
            for(ll k = 0; k < a.size(); k ++ ) {
                rec1[k] = rec[a[k]];
            }
            ll siz = get_combination(n, i); 
            ans += sol.rectangleArea(rec1) / (Z)siz;
        }
        cout << ans << '\n';
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int SAMPLES = 1;
    // cin>>SAMPLES;
    calculate_combinations();
    while (SAMPLES--) SINGLE_TEST();
}