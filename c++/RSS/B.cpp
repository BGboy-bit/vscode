#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll =long long;

constexpr int N = 2E6+10;
constexpr int P = 1E9+7;

ll power(ll a, ll n) {
    ll ans = 1;
    while(n > 0) {
        if(n % 2 == 1) {
            ans = ans * a % P;
            n -- ;
        } else {
            a = a * a % P;
            n /= 2;
        }

    }
    return ans;
}

unordered_map<int,int> mp;

ll dfs(int e,int x){
    if(x==0)return 0;
    if(x==1) return e;
    if(mp.count(x)) return mp[x];
    int l=x/2,r=x-l;
    ll ans=dfs(e,l)%P*power(10,r)%P+dfs(e,r)%P;
    ans%=P;
    return mp[x]=ans;
}

void solve()
{
    mp[0]=0;
    int m;
    cin>>m;
    vector<int> a(10);
    int mn=-1;
    ll sum=m;
    for(int i=0;i<=9;i++){
        cin>>a[i];
        // sum+=a[i];
        if(i>0&&mn==-1&&a[i]>0){
            mn=i;
        }
    }

    if(mn!=-1) a[mn]--,sum--;

    ll ans=0;
    if(mn!=-1){
        // ans=mn*power(10,sum);
        ans=mn;
        ans%=P;
    }

    for(int i=0;i<=9;i++){
        // if(a[i]==0) continue;
        if(sum<=0) break;
        if(sum-a[i]<0){
            a[i]=sum;
        }
        sum-=a[i];
        ans*=power(10,a[i]);
        ans%=P;
        ans+=dfs(i,a[i]);
        ans%=P;
    }
    cout<<ans<<"\n";
    mp.clear();
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
}