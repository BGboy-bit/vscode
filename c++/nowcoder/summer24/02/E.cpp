#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[90];
void solve()
{
	int n,y=-1;
	cin>>n;
	int x=n,t=0;
	while(x){
		a[t++]=x%2;
		x/=2;
	}
	int p=1,f=0;
	for(int i=0;i<t-1;i++){
		if(i)p*=2;
		if(a[i]==1){
			y=p;
			f=1;
			break;
		}
	}
	if(f)
	cout<<n-y<<'\n';
	else cout<<"-1\n";
}

signed main()
{
     int _ = 1;
     cin>>_;
    while (_--)
    {
        solve();
    }
}
