#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr long long INF = 2E18 + 10;
constexpr int N = 2E6 + 10;

int l, r;
map<ll, bool> ok;
ll sqrtt(ll X){
    ll ret=sqrt(X);
    while((ret+1)*(ret+1)<=X) ret++;
    while(ret*ret>X) ret--;
    return ret;
}
// 检查一个数字是否是完全平方数
bool isPerfectSquare(long long x) {
    long long s = sqrtt(x);
    return s * s == x;
}

// 检查一个数字是否可以被分成两个相等长度的部分，并且这两个部分都是完全平方数
bool does(int x) {
    string s = to_string(x);
    int n = s.size();
    if (n % 2 != 0) return false; // 如果数字的长度不是偶数，直接返回 false

    string a = s.substr(0, n / 2);
    string b = s.substr(n / 2);

    long long numA = stoll(a);
    long long numB = stoll(b);

    return isPerfectSquare(numA) && isPerfectSquare(numB);
}

void SINGLE_TEST() {
    int n;
    cin >> n;
    ll l, r; cin >> l >> r;
    int ans = 0;
    for (int i = l; i <= r; i++) {
        ans += does(i);
    }
    cout << ans << "\n";
}

typedef __int128 i128;

inline i128 read() {
    i128 x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + (ch - '0');
        ch = getchar();
    }
    return x;
}

inline void print(i128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) {
        print(x / 10);
    }
    putchar(x % 10 + '0');
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int SAMPLES = 1;
    // cin >> SAMPLES;
    SINGLE_TEST();
}