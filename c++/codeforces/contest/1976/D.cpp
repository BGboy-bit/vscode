#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
typedef array<ll, 2> PII; // vector<PII> a(n+1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 1;

void Solve() {
    string s; cin >> s;
    ll l = s.length();
    s = '!' + s;
    vector<ll> pre(l + 1);
    vector<vector<ll>> ves(l + 1);
    pre[0] = 0;
    for(ll i = 1; i <= l; i ++ ) {
        if(s[i] == '(') pre[i] = pre[i - 1] + 1;
        else pre[i] = pre[i - 1] - 1;
        ves[pre[i]].push_back(i);
    }
    set<ll> high;
    ll ans = 0;
    for(ll i = l, j = l; i >= 0; i -- ) {
        while(i * 2 < j) {
            for(auto k : ves[j]) high.insert(k);
            j -- ;
        }
        ll cnt = 1;
        for(ll k = 1; k < ves[i].size(); k ++ ) {
            auto ff = high.lower_bound(ves[i][k - 1]);
            if(ff != high.end() && *ff < ves[i][k]) {
                cnt = 0;
            }
            ans += cnt;
            cnt ++ ;
        }
    }
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}

// #include <bits/stdc++.h>

// using i64 = long long;

// void solve() {
//     std::string s;
//     std::cin >> s;
    
//     const int n = s.size();
    
//     std::vector<int> pre(n + 1);
//     for (int i = 0; i < n; i++) {
//         pre[i + 1] = pre[i] + (s[i] == '(' ? 1 : -1);
//     }
    
//     std::set<int> high;
//     std::vector<std::vector<int>> vec(n + 1);
//     for (int i = 0; i <= n; i++) {
//         vec[pre[i]].push_back(i);
//     }
//     i64 ans = 0;
//     for (int i = n, j = n; i >= 0; i--) {
//         std::cout << "\n" << "i = " << i << ", " << "j = " << j << "\n";
//         while (j > 2 * i) {
//             for (auto x : vec[j]) {
//                 high.insert(x);
//                 std::cout << x << " ";
//             }
//             j--;
//             std::cout << "\n" << "i = " << i << ", " << "j = " << j << "\nhigh insert:";
//         }
//         std::cout << "\n\n";
//         int cnt = 1;
//         for (int k = 1; k < vec[i].size(); k++) {
//             auto it = high.lower_bound(vec[i][k - 1]);
//             if (it != high.end() && *it < vec[i][k]) {
//                 cnt = 0;
//             }
//             std::cout << "cnt = " << cnt << "\n";
//             std::cout << "high" << ":";
//             for(auto b : high) std::cout << b << " ";
//             std::cout << "\n\n";
//             ans += cnt;
//             cnt++;
//         }
//     }
//     std::cout << ans << "\n";
// }

// int main() {
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(nullptr);
    
//     int t;
//     std::cin >> t;
    
//     while (t--) {
//         solve();
//     }
    
//     return 0;
// }