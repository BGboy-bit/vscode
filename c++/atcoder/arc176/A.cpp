#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m;
bool vis[N];
vector<pair<int, int>> ans;
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int x, y;
		cin >> x >> y;
		vis[(y - x + n) % n] = 1;
	}
	int cnt = m - count(vis, vis + n, 1);
	for (int i = 0; i < n; i++)
		if (vis[i] || cnt){
			if (!vis[i]) cnt--;
			for (int j = 1; j <= n; j++)
				ans.emplace_back(j, j + i > n ? j + i - n : j + i);
		}
	cout << ans.size() << endl;
	for (auto [x, y] : ans)
		cout << x << ' ' << y << endl;
	return 0;
}