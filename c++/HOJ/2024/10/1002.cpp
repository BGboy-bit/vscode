#include <bits/stdc++.h>

#define int long long
#define new _MY_NEW_
#define lg(ITEM) static_cast<int>(std::log2(ITEM))

using namespace std;
using ll = long long;
using PII = std::pair<int, int>;

constexpr long long INF = 2E18 + 10;
constexpr int N = 2E6 + 10;

struct S {
    int l, r;
};

void SINGLE_TEST() {
    int n, m;
    // cin >> n >> m;
    n = 5000, m = 5000;
    vector<int> L(n + 1), R(n + 1), T(n + 1);
    vector<int> le(n + 1), ri(n + 1);
    for (int i = 1; i <= n; i++) {
        // cin >> L[i] >> R[i] >> T[i];
        L[i] = T[i] = 1;
        R[i] = 5000;
        if(i == n) T[i] = 2;
    }
    for (int i = 1; i <= n; i++) {
        if (L[i] + T[i] > R[i]) {
            cout << "NO\n";
            return;
        }
        le[i] = L[i] + T[i];
        ri[i] = R[i] - T[i];
    }
    int left = 1, right = m;
    for (int i = n; i >= 1; i--) {
        int real_l, real_r;
        if (left + T[i] < L[i - 1] || right - T[i] > R[i - 1]) {
            continue;
        }
        real_l = left + T[i] - L[i - 1];
        real_r = right - T[i] - R[i - 1];
        bool ok1 = 1, ok2 = 1;
        for (int j = n - 1; j >= 1; j--) {
            if (left + T[i] > ri[j]) {
                ok1 = 0;
            }
            if (right - T[i] < le[j]) {
                ok2 = 0;
            }
        }
        if (ok1 && ok2) {
            if (real_l > real_r) {
                right = right - T[i];
            } else {
                left = L[i] + real_l;
            }
        } else if (ok1) {
            left = L[i] + real_l;
        } else if (ok2) {
            right = right - T[i];
        } else {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int SAMPLES = 1;
    cin >> SAMPLES;
    for (int CUR = 1; CUR <= SAMPLES; CUR++) {
        SINGLE_TEST();
    }
}
