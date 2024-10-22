#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 5010;
int n, cnt[N][N], deg[N], nd[N];
char mp[N][N];
bool vis[N];
int main() {
	set< int > s;
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++ ) {
		scanf("%s", mp[i] + 1);
		for(int j = 1; j <= n; j ++ ) {
			if(mp[i][j] == '1') cnt[i][j] = 1, deg[i] ++;
		}
		nd[i] = deg[i];
		if(deg[i] > 0) s.insert(i);
	}
	bool ff = 1; vector< int > ans;
	for(int i = 1; i <= 3; i ++ ) {
		if(s.empty()) {
			ff = 0;
			break;
		}
		int maxn = 0, idx = -1;
		for(auto v : s) {
			if(deg[v] > maxn) maxn = deg[v], idx = v;
		}
		ans.pb(idx);
        cout << idx << "\n";
        // 把所有不能到 idx 的点删掉 
        vector<int> del;
        for(int j = 1; j <= n; j ++ ) {
        	bool flag = 1;
        	for(int k = 1; k <= n; k ++ ) {
        		if(cnt[j][k] && !cnt[idx][k]) {
                    cout << j << " " << k << " | " << idx << " " << k << '\n';
        			flag = 0;
        			break;
				}
			}
			if(flag) {
				if(s.find(j) != s.end()) {
                    s.erase(j);
                    del.push_back(j);
                }
			}
		}
        for(auto i : del) {
            cout << i << " ";
        }
        cout << "\n"; 
	}
	if(ff) {
		for(int i = 1; i <= 3; i ++ ) printf("%d ", ans[i - 1]);
	}
	else puts("NOT FOUND");
	return 0;
}
