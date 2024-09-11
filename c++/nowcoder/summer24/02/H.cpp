#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+6;
map<pair<int,int> ,int>mpp;
map<int,int>mp;
int l[N],r[N];
void solve()
{
	int n,x,y,cnt;
	cin>>n>>x>>y;
	string p;
	cin>>p;
	p=' '+p;
	int a=0,s=0,w=0,d=0;
	int ans=0;
	int u,v;
	if(x==0&&y==0){
		cout<<n*(n+1)/2<<'\n';
		return ;
	}
	mpp[{0,0}]=1;
	for(int i=1;i<=n;i++){
		if(p[i]=='W'){
			l[i]=1;
		}
		if(p[i]=='S'){
			l[i]=-1;
		}
		if(p[i]=='A'){
			r[i]=-1;
		}
		if(p[i]=='D'){
			r[i]=1;
		}
		l[i]+=l[i-1];
		r[i]+=r[i-1];
		u=l[i]-y;
		v=r[i]-x;
		mpp[{l[i],r[i]}]++;
		if(mpp[{u,v}]||(u==0&&v==0)){
            mp[cnt]=1;
            ans+=mpp[{u,v}]*(n-i+1);
            mpp[{u,v}]=0;	
		}
	}
	cout<<ans<<'\n';
}

signed main()
{
     int _ = 1;
    while (_--)
    {
        solve();
    }
}