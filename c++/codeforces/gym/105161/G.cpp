#include<bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
using pii = pair<int,int>;

constexpr ll N = 2E6 + 10, inf = 2E18 + 10;

void solve()
{
    int b,t1,a1,t2,a2;
    cin>>b>>t1>>a1>>t2>>a2;
    // double tl=1.0*a1/b+t1;
    if(a1+t1*b<t2*b){
        double ans1=1.0*a1/b;
        double ans2=1.0*a2/b;
        cout<<ans1<<" "<<ans2<<"\n";
    }else{
        double ans1=0,ans2=0;
        a1-=b*(t2-t1);
        ans1+=t2-t1;
        if(a1<a2){
            ans1+=1.0*a1/(b/2.0);
            ans2+=1.0*a1/(b/2.0);
            a2-=a1;
            ans2+=1.0*a2/b;
        }else{
            ans2=1.0*a2/(b/2.0);
            ans1+=1.0*a2/(b/2.0);
            a1-=a2;
            ans1+=1.0*a1/b;
        }
        cout<<ans1<<" "<<ans2<<"\n";
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cout<<fixed<<setprecision(15);
    int T = 1;
    cin>>T;
    while(T--){
        solve();
    }
}