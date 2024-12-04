#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
using PII = pair<int,int>;

constexpr ll INF = 2E18 + 10;
constexpr int N = 2E6 + 10;
int a[N],ans;
map<int,bool>mp;
void dfs(int l,int r,int cnt)
{
	if(cnt>3)return ;
    int x;
    x=l|r;
    if(!mp[x]){
        mp[x]=1;
        ans++;
    }
    dfs(l,x,cnt+1);
    dfs(x,r,cnt+1);
    x=l&r;
    if(!mp[x]){
        ans++;
        mp[x]=1;
    }
    dfs(l,x,cnt+1);
    dfs(x,r,cnt+1);   
    x=l^r;
    if(!mp[x]){
        ans++;
        mp[x]=1;
    }
    dfs(l,x,cnt+1);
    dfs(x,r,cnt+1);
}
void solve()
{
    int n=2;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(!mp[a[i]]){
            mp[a[i]]=1;
            ans++;
        }
    }
    int x;
    for(int i=1;i<n;i++){
        dfs(a[i],a[i+1],1);

    }
    cout<<ans<<"\n";
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