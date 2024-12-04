#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;

constexpr ll INF = 2E18 + 10;
constexpr int N = 4E6 + 10;
constexpr int M=2e6;
int a[N];
int mp[N],sp[N],ma[N],mi[N];

void solve()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]+=M;
        sp[a[i]]++;
        ma[a[i]]=0;
    }
    if(k==0){
        int ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,sp[a[i]]);
        }
        cout<<ans<<'\n';
        return ;
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        mp[a[i]]--;
        mp[a[i]+k]++;
        mi[a[i]]=min(mi[a[i]],mp[a[i]]);
        mi[a[i]+k]=min(mi[a[i]+k],mp[a[i]+k]);
        ma[a[i]]=max(ma[a[i]],mp[a[i]]-mi[a[i]]);
        ma[a[i]+k]=max(ma[a[i]+k],mp[a[i]+k]-mi[a[i]+k]);
    }

    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,sp[a[i]]+ma[a[i]]);
    }

    cout<<ans<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
}