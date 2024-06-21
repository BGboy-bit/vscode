#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
typedef array<int,2> PII;

const int N = 2e6 + 10;



void solve()
{
    int n,W,k;
    cin>>n>>W>>k;
    vector<PII> v(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i][0]>>v[i][1];
    }
    sort(v.begin()+1,v.end(),[&](PII x,PII y){
        return x[1]>y[1];
    });
    vector<int> pr(n+1);
    for(int i=1;i<=n;i++){
        pr[i]=pr[i-1]+v[i][1];
    }
    vector<vector<int>> dp(n+1,vector<int>(W+1));
    vector<vector<int>> ans(n+1,vector<int>(W+1));
    vector<vector<int>> num(n+1,vector<int>(W+1));

    for(int i=1;i<=n;i++){
        for(int j=W;j>=v[i][0];j--){
            if(dp[i-1][j-v[i][0]]+v[i][1]>dp[i][j]){
                num[i][j]=num[i-1][j-v[i][0]]+1;
                ans[i][j]=max(ans[i][j],dp[i][j]+pr[min(n,k+num[i][j])]);
                dp[i][j]=dp[i-1][j-v[i][0]]+v[i][1];
            }
        }
    }
    cout<<ans[n][W]<<"\n";






    // vector<vector<int>> dp(n+1,vector<int>(W+1));
    // for(int i=1;i<=n;i++){
    //     for(int j=W;j>=w[i];j--){
    //         dp[i][j]=max(dp[i][j],dp[i-1][j-w[i]]+v[i]);
    //     }
    // }
    // int t=W;
    // vector<int> vis(n+1);
    // vector<int> so;
    // ll ans=dp[n][W];
    // for(int i=n;i>=1;i--){
    //     for(int j=1;j<=n;j++){
    //         if(vis[j]) continue;
    //         if(dp[i][t]==dp[i-1][t-w[i]]+v[i]){
    //             t-=w[i];
    //             vis[j]=1;
    //             so.push_back(w[i]);
    //             break;
    //         }
    //     }
    // }
    // sort(so.begin(),so.end());
    // reverse(so.begin(),so.end());

    // if(so.size()<=k){

    // }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int testcase=1;
    // cin>>testcase;
    while(testcase--){
        solve();
    }
}
