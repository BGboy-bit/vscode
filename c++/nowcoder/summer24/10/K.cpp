#include <bits/stdc++.h>
//#define int long long
#define PII pair<int,int>
using namespace std;
const int N =2e6+6;
int a[N];

void solve()
{
	int n,q;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	int x=0,y=0,f=0,ans=0;
	for(int i=1,j=1;i<=n&&j<=n;){
		f=0;
		if(a[i]<0){
			if(i-1>=-a[i]){
				if(a[j]>0){
					if(n-j>=(a[j]-a[i]))f=1;
				}else f=1;
			}
		}
		
		//->
		if(a[j]>=0){
			if(n-j>=a[j]){
				if(a[i]<0){
					if(i-1>=-(a[i]-a[j]))f=1;
				}else f=1;
			}
		}
		if(f){
			ans=max(ans,j-i+1);
			j++;
		}else {
			i++;
		}
	}
	 cout<<ans<<'\n';
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
	int T=1;
	cin>>T;
	while(T--){
		solve();
	}
    return 0;
}
