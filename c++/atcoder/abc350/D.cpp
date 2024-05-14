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
bool multi = 0;
 
const int maxn = 200100;

int n, m, fa[maxn], sz[maxn];

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

inline void merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y) {
		fa[x] = y;
		sz[y] += sz[x];
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		fa[i] = i;
		sz[i] = 1;
	}
	ll ans = -m;
	while (m--) {
		int x, y;
		scanf("%d%d", &x, &y);
		merge(x, y);
	}
	for (int i = 1; i <= n; ++i) {
		if (fa[i] == i) {
			ans += 1LL * sz[i] * (sz[i] - 1) / 2;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
