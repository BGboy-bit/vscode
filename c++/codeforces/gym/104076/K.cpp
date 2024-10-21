#include<bits/stdc++.h>
using namespace std;
#define int long long
using ll = long long;
const int N=2e6+6;
int p[N],v[N];
void solve()
{
    int n;cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        v[i]=1;
        p[a[i]]=i;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(v[a[i]]){
            ans++;
        }else continue;
        int x=a[i],y=i;
        while(1){
            v[x]=0;
            x--;
            if(x<1||p[x]<p[x+1]||v[x]==0)break;
        }

    }
    cout<<ans<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
}