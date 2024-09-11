#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+6;
int a[N];
int b[100];
int c[100];
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=0;i<=65;i++)b[i]=0;

    for(int i=1;i<=n;i++){
        int j=1,cnt=0;
        for(;j<=a[i];j*=2){
            if(a[i]&j){
                if(b[cnt]==0){
                    c[cnt]=i;
                }
                b[cnt]++;
            }
            cnt++;
        }
    }
    int q=0;
    for(int i=0;i<=65;i++){
        if(b[i]==0)continue;
        if(b[i]!=2){
            cout<<"-1\n";
            return ;
        }
        q++;
    }
    cout<<q<<'\n';
    int x=1;
    for(int i=0;i<=65;i++){
        if(i)x*=2;

        if(b[i]==2){
            cout<<c[i]<<' '<<x<<'\n';
        }
    }
    
}
signed main()
{
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
}