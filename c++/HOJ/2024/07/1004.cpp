#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+6;
const int mod=1e9+7;
int h[N];
vector<int> a[N];
int c,ma;
void dfs(int u,int fa,int dep)
{
	int d=0;
	if(dep>ma){
		ma=dep;
		c=u;
	}
	for(auto i:a[u]){
		if(i==fa)continue;
		dfs(i,u,dep+1);
		d=max(d,h[i]);
	}
	h[u]=d+1;
}
void solve()
{
	int n,s,r1,r2;
	cin>>n>>s>>r1>>r2;
	int u,v;
	for(int i=1;i<=n;i++)a[i].clear();
	for(int i=1;i<n;i++){
		cin>>u>>v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for(auto i:a[s]){
		dfs(i,s,1);
	}
	ma=0;
	dfs(c,0,1);   
	if(r1*2>=r2){
		cout<<"Kangaroo_Splay\n";
		return ;
	}

	if(ma<=r1*2+1){
		cout<<"Kangaroo_Splay\n";
		return ;
	}
	cout<<"General_Kangaroo\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--){
    	solve();
	}
        
}
