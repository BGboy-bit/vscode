#include<bits/stdc++.h>
#define int long long
#define PII pair<int ,int>
using ll = long long;
using namespace std;
constexpr ll INF = 2E18+10;
const int N=2e5+6;
int pre[N];
int ne[N],d[N];
void solve()
{
    int n;cin>>n;
    vector<int> a(n+3);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        pre[i]=i-1;
        ne[i]=i+1;
        d[i]=1;
    }
    priority_queue<PII,vector<PII>,greater<PII>> q;

    for(int i=1;i<=n;i++){
        q.push({a[i],i});
    }
    a[0]=1e9+4;
    a[n+1]=1e9+5;
    ll ans=0,x,y;
    PII s;
    for(int i=1;i<=n-1;i++){
        s=q.top();
        q.pop();
        x=s.first,y=s.second;
        if(pre[y]==n+1||a[pre[y]]<=a[ne[y]]){
            if(a[pre[y]]!=a[y])ans+=d[y];
            d[pre[y]]+=d[y];
            ne[pre[y]]=ne[y];
            
        }else {
            if(a[ne[y]]!=a[y])ans+=d[i];
            d[ne[y]]+=d[y];
            pre[ne[y]]=pre[y];
        }
    }
    cout<<ans<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
}