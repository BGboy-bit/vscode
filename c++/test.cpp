#include<bits/stdc++.h>
#define ll long long
using namespace std;
int t;
int n;
int s1,s2;
int m1,m2;
vector<int> g1[1010],g2[1010];
priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > > q;
ll dis[1010][1010];
bool b[1010][1010];
int bb[1010];
ll ans=1e18;
inline void dij()
{
	for(register int i=1;i<=n;i++)
		for(register int j=1;j<=n;j++)
		{
			if(i==s1&&j==s2) dis[i][j]=0;
			else dis[i][j]=1e18;
			b[i][j]=0;
		}
	q.push({0,{s1,s2}});
	while(!q.empty())
	{
		int k1=q.top().second.first,k2=q.top().second.second;
		q.pop();
		if(b[k1][k2]) continue;
		b[k1][k2]=1;
		for(register int i=0;i<g1[k1].size();i++)
			for(register int j=0;j<g2[k2].size();j++)
			{
				int x1=g1[k1][i],x2=g2[k2][j];
				if(dis[k1][k2]+abs(x1-x2)<dis[x1][x2])
				{
					dis[x1][x2]=dis[k1][k2]+abs(x1-x2);
					if(!b[x1][x2]) q.push({dis[x1][x2],{x1,x2}});
				}
			}
	}
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&s1,&s2);
		scanf("%d",&m1);
		for(register int i=1;i<=m1;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			g1[u].push_back(v),g1[v].push_back(u);
		}
		scanf("%d",&m2);
		for(register int i=1;i<=m2;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			g2[u].push_back(v),g2[v].push_back(u);
		}
		dij();
		for(register int i=1;i<=n;i++)
		{
			for(register int j=1;j<=n;j++) bb[j]=0;
			for(register int j=0;j<g1[i].size();j++) bb[g1[i][j]]++;
			for(register int j=0;j<g2[i].size();j++) bb[g2[i][j]]++;
			int f=0;
			for(register int j=1;j<=n;j++) if(bb[j]==2){f=1;break;}
			if(!f) continue;
			cout << i << " " << dis[i][i] << "\n";
			ans=min(ans,dis[i][i]);
		}
		if(ans==1e18) puts("-1");
		else printf("%lld\n",ans);
		for(register int i=1;i<=n;i++) g1[i].clear(),g2[i].clear();
		ans=1e18;
	}
	return 0;
}
