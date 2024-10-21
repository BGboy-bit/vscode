#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include<bits/stdc++.h>
using namespace std;
#define int long long
using ll = long long;
constexpr int N=502;
int n,k;
int a[N];
// unordered_map<int ,int>dp[N];
// int dp[1e9][N];
// set<int> np[N];
unordered_map<int,multiset<int>> np;

// multiset<unordered_map<int,int>> dp;
// int tmp[N];
int cnt[35];
void solve()
{
    cin>>n>>k;
    // n=500,k=0;
    int mi=1e9;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mi=min(mi,a[i]);
        // a[i]=1e9;
    }

    sort(a+1,a+n+1);

    unordered_set<int>s;

    for(int i=1;i<=n;i++){
        int cnt=0;
        int x=a[i];
        while(x){
            if(x>=mi&&x-mi>n*30){
                x/=2;
                continue;
            }
             s.insert(x);
            //  dp[i][x]=cnt++;


            x/=2;
        }
    }
    
    for(int i=1;i<=n;i++){
        for(auto const &x:s){
            int sm=1e9,p=0,cn=a[i];

            int l=0,r=30,mid;
            if(cn<=x){
                sm=x-cn;
                // dp[i][x]=sm;
                np[x].insert(sm);
                continue;
            }
           while(l<r){
                mid=(l+r+1)/2;
                if(cn/cnt[mid]>=x){
                    l=mid;
                }else r=mid-1;
            }
            // l=log2(cn/x);
            sm=min(l+(cn/cnt[l]-x),sm);
            l++;
            if(cn/cnt[l]>0){
                sm=min(l+abs(x-cn/cnt[l]),sm);
            }
            // dp[i][x]=sm;
            np[x].insert(sm);

            // cout<<a[i]<<' '<<x<<' '<<sm<<'\n';
        }
    }
    int ans=1e9;
    // vector<int>tmp;

    for(auto const &x:s){
        int sm=0;
        // tmp.clear();
        // for(int i=1;i<=n;i++){
        //     // tmp.push_back(dp[i][x]);
        //     tmp[i]=dp[i][x];
        // }
        // sort(tmp+1,tmp+n+1);
        // for(int i=1;i<=n-k;i++){
        //     sm+=tmp[i];
        // }
        int kk=n-k;
        while(kk--){
            sm+=*np[x].begin();
            np[x].erase(np[x].begin());
        }
        ans=min(ans,sm);
    }
    cout<<ans<<'\n';
    for(auto  &[key,val] : np){
        val.clear();
    }
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