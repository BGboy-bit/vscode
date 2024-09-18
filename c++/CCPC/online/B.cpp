#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
using PII = pair<int,int>;

constexpr ll INF = 2E18+10;
constexpr int N = 1E6+10;
constexpr int P =998244353;

int g[N];

ll jc[N];

void solve()
{
    int n;cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        g[a[i]]++;
    }
    ll ans=0;
    sort(a.begin()+1,a.end());
    for(int l=1;l<=n;l++){
        for(int r=l+1;r<=n;r++){
            ans+=a[r]-a[l];
        }
    }
    ll sum=2;
    if(g[a[1]]==n){
        sum=1;
    }
    for(int i=1;i<=1000000;i++){
        if(g[i]==0) continue;
        sum*=jc[g[i]];
        sum%=P;
    }
    if(n==1){
        sum=1;
    }
    cout<<ans<<" "<<sum<<"\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    jc[0]=1;
    for(int i=1;i<=1000000;i++){
        jc[i]=jc[i-1]*i;
        jc[i]%=P;
    }
    int T=1;
    // cin>>T;
    for(int i=1;i<=T;i++){
        solve();
    }
}
