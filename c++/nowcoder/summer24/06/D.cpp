#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=2e5;
vector<int> a[N];
pair<int,int> b[N],c[N],an[N];
int p[N],f=1,s[N];
int he=0,tt,n,m,su=0,x,y;
map<pair<int,int>,int>mp;
int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void dfs(int u,int fa,int xx)
{
	for(auto i:a[u]){
		if(i==fa)continue;
//		if(s[i]==n)continue;
		x=min(i,u);
		y=max(i,u);
		if(mp[{x,y}])continue;
		if(s[i]==xx){
			c[tt++]={u,i};
			while(tt>0){
				he++;
//				s[c[tt-1].first]=n;
				x=find(c[tt-1].first);
				y=find(c[tt-1].second);
		
				if(x>y)swap(x,y);
				if(x!=y){
					p[y]=x;
				}
				
					x=min(c[tt-1].first,c[tt-1].second);
					y=max(c[tt-1].first,c[tt-1].second);
					an[su++]={x,y};
					mp[{x,y}]=1;
				tt--;
				if(i==c[tt-1].first){
					he++;
//					s[c[tt-1].first]=n;
					x=min(c[tt-1].first,c[tt-1].second);
					y=max(c[tt-1].first,c[tt-1].second);
					an[su++]={x,y};
					mp[{x,y}]=1;
					tt--;
					break;
				}
			}
			if(tt<0)tt=0;
			continue;
		}
		c[tt++]={u,i};
	
		s[i]=xx;
		dfs(i,u,xx);
	}
}
void solve()
{
	cin>>n>>m;
	int u,v,t=0,q=0;
	for(int i=1;i<=n;i++)p[i]=i;
	string ss;
	for(int i=1;i<=m;i++){
		cin>>u>>v;
		cin>>ss;
		if(u>v){
			swap(u,v);
		}
		if(ss=="Lun"){
			a[u].push_back(v);
			a[v].push_back(u);
//			p[v]=find(u);
			
			q++;
		}else {
			b[t++]={u,v};
		}
	}
	for(int i=1;i<=n;i++){
		tt=0;
		if(!s[i]){
			s[i]=i;
			dfs(i,0,i);
		}
	}
	
	for(int i=0;i<t;i++){
		x=find(b[i].first);
		y=find(b[i].second);
		if(x>y)swap(x,y);
		if(x!=y){
			an[su++]=b[i];
			p[y]=x;
		}
	}
	for(int i=1;i<=n;i++){
		x=find(i);
		if(p[x]!=1){
			cout<<"NO\n";
			return ;
		}
	}
	cout<<"YES\n";
	cout<<su<<'\n';
	for(int i=0;i<su;i++){
		cout<<an[i].first<<' '<<an[i].second<<'\n';
	}
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T=1;
//    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}