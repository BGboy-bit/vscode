#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
using PII = pair<int,int>;

constexpr ll INF = 2E18+10;
constexpr int N = 2E6+10;
constexpr int P =998244353;

template<class T>
constexpr T power(T a,ll b,ll mod=P-2){
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


void solve()
{
    int n,k;
    cin>>n>>k;

    if(k==1){
        if(n%2==1){
            cout<<"Alice\n";
        }else cout<<"Bob\n";
        return ;
    }

    if(k>=n){
        cout<<"Alice\n";
        return ;
    }

    if(n%2==1){
        cout<<"Alice\n";
        return ;
    }
    bool f=0;
    for(int i=2;i<=n/i;i++){
        if(n%i==0){
            if(i%2==0&&i<=k&&(n/i)%2==1||(n/i)%2==0&&(n/i)<=k&&i%2==1)f=1;
        }
    }
    if(f){
        cout<<"Alice\n";
    }else cout<<"Bob\n";

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    cin>>T;
    for(int i=1;i<=T;i++){
        solve();
    }
}
