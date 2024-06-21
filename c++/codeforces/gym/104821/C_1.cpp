#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long

const int N = 1e5 + 10;

int primes[N],cnt;
bool st[N];
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


void solve(ll p,ll m)
{
    // ll p, m; 
    // cin >> p >> m;
    // cout<<m/(p+1) + 1<<"\n";
    int ans=0;
    for(int g=0;g<=m;g++){
        if((g^(p-1))%p==1){
            ans++;
            cout<<g<<" ";
        }
    }
    cout<<"\n";
    cout<<"ans: "<<ans<<"\n";
    if(m/(p+1) + 1!=ans){
        // cout<<m/p+1<<" "<<m/(p+1) + 1<<" "<<ans<<"\n";
        cout<<"NO\n";
    }else{
        // cout<<m/p+1<<" "<<m/(p+1) + 1<<" "<<ans<<"\n";
        cout<<"YES\n";
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    get_primes(N);
    // for(int i=1;i<=10;i++){
    //     for(int j=0;j<=20;j++){
    //         cout<<primes[i]<<" "<<j<<"\n";
    //         solve(primes[i],j);
    //     }
    // }
    solve(7,11);
    // int testcase=1;
    // cin>>testcase;
    // while(testcase--){
    //     solve();
    // }
}
