#include<bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
using pii = pair<int,int>;

constexpr ll N = 2E6 + 10, INF = 2E18 + 10;

void solve()
{
    int n;
    cin>>n;
    vector<pii> a(n+1);
    
    for(int i=1;i<=n;i++){
        cin>>a[i].first;
        a[i].second=i;
    }
    
    sort(a.begin()+1,a.end());
    int t=0;
    map<int,bool> vis;
    map<int,int> val;
    for(int i=1;i<=n;i++){
        if(!vis[a[i].first]){
            vis[a[i].first]=1;
            val[a[i].first]=++t;
        }
    }
    for(int i=1;i<=n;i++){
        a[i].first=val[a[i].first];
    }
    vector<int> num(t+1);
    for(int i=1;i<=n;i++){
        num[a[i].first]++;
    }
    for(int i=1;i<=t;i++){
        num[i]+=num[i-1];
        // cout<<num[i]<<" ";
    }
    // cout<<"\n";
    // for(int i=1;i<=n;i++){
    //     auto [x,y]=a[i];
    //     cout<<x<<" "<<y<<"\n";
    // }
    int mn=INF;
    for(int i=n;i>=1;i--){
        if(a[i].second>mn){
            // cout<<num[a[i].first-1]+1<<"\n";
            int ans=num[a[i].first-1];
            for(int j=1;j<=n;j++){
                if(a[j].second>mn&&a[j].first==a[i].first){
                    ans++;
                }
            }
            cout<<ans<<"\n";
            return ;
        }
        mn=min(mn,a[i].second);
    }
    cout<<0<<"\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
}