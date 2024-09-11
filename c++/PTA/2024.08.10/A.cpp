#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+6;
int a[N];
void solve()
{
    int n=0,x,s;
    cin>>s>>x;
    // s=rand()+2e6;
    // x=rand()+2e6;
    if(__gcd(s,x)==1){
        cout<<"1\n";
        cout<<s<<'\n';
        return ;
    }
    if(x%2==0&&s%2){
        a[1]=-1;
        s++;
        n++;
    }
    int f=0;
    for(int i=1;i<=1e6;i++){
        if(__gcd(i,x)==1&&__gcd(s-i,x)==1){
            a[++n]=i;
            a[++n]=s-i;
            f=1;
            break;
        }
    }
    if(!f){
        cout<<"NO\n";
    }
    cout<<n<<'\n';
    for(int i=1;i<=n;i++){
        cout<<a[i]<<' ';
    }
}
signed main()
{
    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
}