#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
using PII = pair<int,int>;

constexpr ll INF = 2E18+10;
constexpr int N = 2E3+10;
constexpr int P = 998244353;

template<class T>
constexpr T power(T a,ll b=P-2,ll mod=P){
    a%=mod;
    T res=1;
    for(;b;b/=2,a*=a,a%=mod){
        if(b%2){
            res*=a;
            res%=mod;
        }
    }
    return res;
}

ll dp[N][N][30];

void solve()
{

    cout<<(26*26+26-1)*power(26*26)%P;

    int n,m;
    cin>>n>>m;

    for(int j=1;j<=m;j++){
        for(int k=1;k<=26;k++){
            dp[1][j][k]=power(26);
            cout<<dp[1][j][k]<<"\n";
        }
        
    }

    // dp[n][m][k]=(26-(k-1))/26*dp[n-1][m][k-1]+(k-1)/26*dp[n-1][m][k]
    for(int i=2;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int k=1;k<=26;k++){
                dp[i][j][k]=(26-(k-1)) * power(26) * dp[i-1][j][k-1]
                            +
                            (k-1) * power(26) *dp[i-1][j][k];
                dp[i][j][k]%=P;
                cout<<dp[i][j][k]<<" ";
            }
        }
    }
    cout<<"\n";
    ll ans=0;
    for(int i=1;i<=26;i++){
        ans+=dp[n][m][i];
        cout<<dp[n][m][1]<<" ";
        ans%=P;
    }
    cout<<"\n";
    ans*=power(26);
    cout<<ans<<"\n";
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