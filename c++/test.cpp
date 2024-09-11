#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#endif

#define int long long
#define new _MY_NEW_
#define lg(ITEM) static_cast<int>(std::log2(ITEM))

using namespace std;
using ll = long long;
using PII = std::pair<int, int>;

constexpr long long INF = 2E18 + 10;
constexpr int N = 2E6 + 10;

void SINGLE_TEST() {
    int n;
    cin >> n;
    multiset<int, greater<>> se1, se2;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        se1.emplace(x);
    }
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        se2.emplace(x);
    }
    bool t = 1;
    int ans1 = 0, ans2 = 0;
    while (1) {
        int t1 = *se1.begin();
        int t2 = *se2.begin();
        if (min(t1, t2) == 1) {
            break;
        }
        if (t) {
            se1.emplace(1);
            se2.erase(se2.begin());
            se2.emplace(1);
            ans1 += 3;
        } else {
            se2.emplace(1);
            se1.erase(se1.begin());
            se1.emplace(1);
            ans2 += 3;
        }
        t ^= 1;
    }
    if (t) {
        ans1 += se1.size() + se2.size();
    } else {
        ans2 += se1.size() + se2.size();
    }
    if (ans1 > ans2) {
        cout << "shuishui\n";
    } else if (ans1 < ans2) {
        cout << "sha7dow\n";
    } else {
        cout << "Tie\n";
    }
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
