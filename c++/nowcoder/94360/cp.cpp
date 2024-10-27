#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
using PII = pair<int,int>;

constexpr ll INF = 2E18 + 10;
constexpr int N = 2E6 + 10;

void solve()
{
    int n,a,b;
    cin>>n>>a>>b;
    if(a==b){
        cout<<n<<'\n';
        return ;
    }
    if(a==0){
        cout<<1ll<<'\n';
        return ;
    }
    int ans=1;
    if(a*2<=b){
        int p=b/a;
        // int ans=1;
        n--;
        ans+=(n/(p));
        
    }else {
        // int ans=1;
        n--;
        int p=(b/(b-a));
        ans+=(n/p*(p-1));
        if(n%p){
            ans+=(n%p-1);
        }
    }
    cout<<ans<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
}