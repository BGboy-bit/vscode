#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
using PII = pair<int,int>;
const int N=106;
const int mod=998244353;

string s, t;
int dp[N][N],f[N][N];

void solve()
{
    cin>>s>>t;
    int n=s.size(),m=t.size();
    s=' '+s;
    t=' '+t;
    for(int p=1;p<=n;p++){
        for(int i=1;i<=m;i++){
            for(int j=i;j<=m;j++){
                f[i][j]=0;
                
                    if(t[i]==s[p]){
                        f[i][j]=(f[i][j]+dp[i+1][j])%mod;
                    }
                for(int k=i;k<j;k++){
                    f[i][j]=(f[i][j]+dp[i][k]*dp[k+1][j]%mod)%mod;
                    if(t[k]==s[p]){
                        f[i][j]=(f[i][j]+dp[i][k-1]*dp[k+1][j]%mod)%mod;
                    }
                }
                    if(t[j]==s[p]){
                        f[i][j]+=dp[i][j-1];
                        f[i][j]%=mod;
                    }
                // dp[i][j]=dp[i][j]*2+f[i][j];
            }
        }
        for(int i=1;i<=m;i++){
            for(int j=i;j<=m;j++){
                
                dp[i][j]=dp[i][j]*2+f[i][j];
                dp[i][j]%=mod;
                if(i==j&&s[p]==t[i])dp[i][j]+=1;
            }
        }
    }

    cout<<dp[1][m]%mod<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    // cin>>T;
    for(int i=1;i<=T;i++){
        solve();
    }
}
