#include <bits/stdc++.h>

#define lowit(x) (x & -x)

#define range(x) x.begin(), x.end()

using namespace std;

using ll = long long;
using i64 = long long;
using LL = long long;
using PII = pair<ll, ll>;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	vector<PII> v,ans;
	for(int i = 3;i < n ;i ++){
		cout <<"? "<< 1 <<" "<<i << endl;
		cin >> a[i];
		if(a[i] == 0){
			ans.push_back({1,i});
		}
	}
	v.push_back({2,n});
	for(int i = 3;i <= n ;i ++){
		int c = a[i] - a[i - 1];
		if(c < 0){
			for(int j = 0 ;j < -c;j ++){
				ans.push_back({v.back().first,i});
				v.back().second --;
				if(v.back().second == 0)v.pop_back();
			}
		}else if(c > 0){
			v.push_back({i - 1,c});
		}
	}
	while(ans.size() < n - 3){
		ans.push_back({v.back().first,n});
		v.back().second --;
		if(v.back().second == 0)v.pop_back();
	}
	cout <<"! ";
	for(auto [x,y]:ans){
		cout << x <<" "<<y <<" ";
	}
	cout <<endl;
	int ok;
	cin >> ok;
	assert(ok);
}

int main() {
    cout << fixed << setprecision(12);
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++)
        solve();
    return 0;
}