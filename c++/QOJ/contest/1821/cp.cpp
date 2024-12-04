#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
using PII = pair<int,int>;

constexpr ll INF = 2E18 + 10;
constexpr int N = 2E6 + 10;

void solve()
{
    int a,b,c;
    cin>>a>>b>>c;
    cout<<100<<"\n";
    for(int i=1;i<=50;i++){
        cout<<1<<" ";
    }
    for(int i=51;i<=95;i++){
        cout<<b<<" ";
    }
    for(int i=1;i<=4;i++){
        cout<<c<<" ";
    }
    cout<<(int)1e9<<" ";
    cout<<"\n";
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