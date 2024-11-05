#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;

constexpr ll INF = 2E18 + 10;
constexpr int N = 2E6 + 10;
int a[N];
unordered_map<int,int>mp,sp;

void solve()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(a[i]!=a[i-1]){
            cnt=0;
        }
        cnt++;
        sp[a[i]]++;
        mp[a[i]]=max(mp[a[i]],cnt); 
    }
    int ans=0;

    for(int i=1;i<=n;i++){
        ans=max(ans,sp[a[i]]);
    }
    if(k==0){
        cout<<ans<<'\n';
        return ;
    }
    for(int i=1;i<=n;i++){
        ans=max(ans,mp[a[i]-k]+sp[a[i]]);
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