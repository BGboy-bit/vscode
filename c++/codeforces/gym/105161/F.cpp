#include<bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
using pii = pair<int,int>;

constexpr ll N = 2E6 + 10, inf = 2E18 + 10;

void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]+=a[i-1];

    }
    for(int i=k;i<=n;i++){
        double x=a[i]-a[i-k];
        x=x*1.0/(k*1.0);
        if(x>=1024){
            x=x/1024;
            cout<<x<<" MiBps\n";
        }else {
            cout<<x<<" KiBps\n";
        }
    }

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cout<<fixed<<setprecision(6);
    int T = 1;
    // cin>>T;
    while(T--){
        solve();
    }
}