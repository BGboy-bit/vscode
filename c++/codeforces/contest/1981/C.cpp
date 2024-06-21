// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;

// string ToBinary(ll num) {
//     bitset<32> b(num);
//     string s = b.to_string();
//     auto pos = s.find_first_not_of('0');
//     if (pos != string::npos) {
//         return s.substr(pos);
//     }
//     return "";
// }

// void Solve() {
//     ll n; cin >> n;
//     vector<ll> a(n + 1), b;
//     a[0] = 0;
//     bool ff = 0;
//     for(ll i = 1; i <= n; i ++ ) {
//         cin >> a[i];
//         if(a[i] == -1) ff = 1;
//         if(a[i] >= 1 && a[i - 1] == -1) b.push_back(i); // 右
//         if(a[i] == -1 && a[i - 1] >= 1) b.push_back(i); // 左
//     }
//     if(b.size() == 0) { // 全为-1
//         if(ff) {
//             for(ll i = 1; i <= n; i ++ ) cout << (1ll << i) << " \n"[i == n];
//         }
//         else {
//             for(ll i = 1; i <= n; i ++ ) {
//                 if(i < n && a[i] / 2 != a[i + 1] && a[i + 1] / 2 != a[i] || i == n && a[i - 1] / 2 != a[i] && a[i] / 2 != a[i - 1]) {
//                     cout << "-1" << "\n"; return ;
//                 } 
//             }
//             for(ll i = 1; i <= n; i ++ ) {
//                 cout << a[i] << " \n"[i == n];
//             }
//         }
//         return ;
//     }
//     for(ll i = 0; i < b.size(); i ++ ) {
//         if(a[b[i]] == -1 && i != b.size() - 1) {
//             ll u = b[i] - 1, v = b[i + 1], u1 = -1, v1 = -1; i ++ ;
//             for(ll j = 30; j >= 0; j -- ) {
//                 ll x = 1ll << j;
//                 if(a[u] >= x && u1 == -1) u1 = j;
//                 if(a[v] >= x && v1 == -1) v1 = j;
//             }   
//             if(a[u] >= a[v]) { // 左端点大于等于右端点
//                 if(u1 - v1 > v - u || (v - u - (u1 - v1)) % 2 != 0) {
//                     cout << "-1" << "\n"; return;
//                 }
//                 for(u = u + 1; u < v; u ++ ) {
//                     if(a[u - 1] > a[v]) {
//                         a[u] = a[u - 1] >> 1;
//                     } else a[u] = a[u - 1] << 1;
//                 }
//             } else if(a[u] < a[v]) { // 左端点小于右端点
//                 ll cnt = v1 - u1;
//                 ll cnt1 = 0;
//                 string s1 = ToBinary(a[u]), s2 = ToBinary(a[v]);
//                 for(ll j = 0; j < s1.size(); j ++ ) {
//                     if(s1[j] != s2[j]) {
//                         cnt1 = s1.size() - j;
//                         cnt += cnt1;
//                         break;
//                     }
//                 }
//                 if(cnt1 + cnt > v - u || (v - u - cnt - cnt1) % 2 != 0) {
//                     cout << "-1" << "\n"; return;                    
//                 } 
//                 for(u = u + 1; u < v; u ++ ) {
//                     if(cnt1 > 0) {
//                         a[u] = a[u - 1] >> 1;
//                         cnt1 -- ;
//                     } else if(cnt < 0) {
//                         a[u] = a[u - 1] >> 1;
//                         cnt ++ ;
//                     } else {
//                         ll y = 1ll << (-- cnt);
//                         if(y & a[v]) 
//                             a[u] = (a[u - 1] << 1) + 1;
//                         else 
//                             a[u] = a[u - 1] << 1;
//                     }
//                 }
//             }
//         } else if(a[b[i]] >= 1) { // 左半区间
//             ll u = b[i] - 1;
//             for(;u >= 0; u -- ) {
//                 if(a[u + 1] != 1) a[u] = a[u + 1] / 2;
//                 else a[u] = a[u + 1] * 2;
//             }
//         } else if(a[b[i]] == -1 && i == b.size() - 1) { // 右半区间
//             ll u = b[i];
//             for(;u <= n; u ++ ) {
//                 if(a[u - 1] == -1) a[u] = a[u + 1] / 2;
//                 else a[u] = a[u - 1] * 2;
//             }
//         }
//     }
//     for(ll i = 1; i <= n; i ++ ) cout << a[i] << " \n"[i == n];
// }

// signed main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0); cout.tie(0);
//     ll T; cin >> T;
//     while(T -- ) {
//         Solve();
//     }
//     return 0;
// }
#include <stdio.h>
#include <vector>
using namespace std;

int main() {
	vector<bool> s;
	vector<int> p;
	s.resize(1000000);
	for (int i = 2; i < 1000000; i++) {
		if (s[i])
			continue;
		p.push_back(i);
		for (int j = i * 2; j < 1000000; j += i) {
			s[j] = true;
		}
	}
	int t;
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++) {
		int n;
		scanf("%d", &n);
		int m = 1;
		while (true) {
			if (m & 1) {
				if (m * (m + 1) / 2 >= n - 1)
					break;
			} else {
				if (m * (m + 1) / 2 - m / 2 + 1 >= n - 1)
					break;
			}
			m++;
		}
		vector<int> off(m);
		int cur = 0;
		for (int i = 0; i < n; i++) {
			printf("%d ", p[cur]);
			cur = (cur + off[cur]++) % m;
		}
		printf("\n");
	}
}
