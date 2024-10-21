#include<bits/stdc++.h>
using namespace std;
#define int long long
using ll = long long;
const int N=502;
int n,k;
int a[N];
unordered_map<int ,int>dp[N];
int tmp[N];
int cnt[35];
void solve()
{
    cin>>n>>k;
    // n=500,k=0;
    int mi=1e18;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mi=min(mi,a[i]);
        // a[i]=1e9;
    }

    unordered_set<int>s;

    for(int i=1;i<=n;i++){
        int cnt=0;
        int x=a[i];
        while(x){
            
            s.insert(x);
            // dp[i][x]=cnt++;
            x/=2;
        }

    }
    
    int ans=1e18;
    // vector<int>tmp;

    for(auto x:s){
        int sm=0;
        // tmp.clear();
        for(int i=1;i<=n;i++){
            int cn=a[i];
            if(cn<=x){
                tmp[i]=x-xp;
            }
            while(cn){
                if(cn>=x){
                    sm=min(p+(cn-x),sm);
                }else {
                    sm=min(sm,p+(x-cn));
                    break;
                }
                cn/=2;
                p++;
            }
        }
        sort(tmp+1,tmp+n+1);
        for(int i=1;i<=n-k;i++){
            sm+=tmp[i];
        }
        ans=min(ans,sm);
    }
    cout<<ans<<'\n';

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cnt[0]=1;
    for(int i=1;i<=31;i++){
        cnt[i]=cnt[i-1]*2;
    }
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
}