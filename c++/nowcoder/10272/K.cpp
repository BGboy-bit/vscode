#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;

constexpr ll INF = 2E18 + 10;
constexpr int N = 2E6 + 10;
int p[N];
void solve()
{
    int n,k;
    cin>>n>>k;
    if(n==1&&k==1){
        cout<<"1\n";
        return ;
    }
    if(k==0||k==n){
        cout<<"-1\n";
        return ;
    }
    for(int i=n-k+1;i<=n;i++){
        p[i]=i;
    }
    for(int i=1;i<n-k;i++){
        p[i]=(i+1);
    }
    p[n-k]=1;
    for(int i=1;i<=n;i++){
        cout<<p[i]<<' ';
    }
    cout<<'\n';
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