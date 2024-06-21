#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
#define INF ll(2e18+10)

const int N = 1e5 + 10;

int primes[N],cnt;
bool st[N];
ll po[100];
void get_primes(int n)
{
    cnt=1;
    for(int i=2;i<=n;i++){
        if(!st[i]) primes[cnt++]=i;
        for(int j=1;primes[j]<=n/i;j++){
            st[primes[j]*i]=true;
            if(i%primes[j]==0) break;
        }
    }
    cnt--;
}

ll mx=0;
void solve(ll p,ll m)
{
    // ll p, m; 
    // cin >> p >> m;
    // cout<<m/(p+1) + 1<<"\n";
    // int v=*lower_bound(po,po+58+1,p);
    int v;
    // for(int i=0;i<=60;i++){
    //     cout<<po[i]<<" ";
    // }
    for(int i=0;i<=60;i++){
        if(po[i]>=p){
            v=po[i];break;
        }
    }
    // cout<<v<<" "<<p<<"\n";
    int ans=0;
    for(int g=0;g<=m;g++){
        if((g^(p-1))%p==1){
            ans++;
            // cout<<g<<" ";
        }
    }
    // if(v==0) return ;
    if(ans-(m/(v))>15){
        cout<<p<<" "<<m<<" ";
        cout<<ans-(m/(v))<<" ";
        cout<<"WA\n";
    }
    mx=max(mx,ans);
}

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr),cout.tie(nullptr);

    get_primes(N);
    po[0]=1;
    for(int i=1;i<=60;i++){
        if(po[i-1]<INF/2){
            po[i]=po[i-1]*2;
        }else break;
    }
    for(int i=2;i<=50;i++){
        for(int j=0;j<=200;j++){
            // cout<<primes[i]<<" "<<j<<"\n";
            solve(primes[i],j);
        }
    }
    cout<<mx<<"\n";

    // for(int i=0;i<=60;i++){
    //     cout<<po[i]<<" ";
    // }
    // cout<<"\n";
    // solve(1145141,998244353);
    // for(int i=1145141*871;i<=1145141*872;i++){
    //     if((i^1145140)%1145141==1){
    //         cout<<i-1145141*871<<" ";
    //     }
    // }
    // cout<<"\n";
    // int testcase=1;
    // cin>>testcase;
    // while(testcase--){
    //     solve();
    // }
}
