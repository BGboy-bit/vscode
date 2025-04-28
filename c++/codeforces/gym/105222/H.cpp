#include<bits/stdc++.h>
#define int long long
using namespace std;

using ll = long long;
using pii = pair<int,int>;

constexpr ll N =2E6 + 10, inf = 2E18 + 10;

void solve()
{
    int n;
    cin>>n;
    int v=n%3+n/3;

    if(n%3==0){
        cout<<"1 "<<v<<'\n';
    }else cout<<"0 "<<v<<"\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    cin>>T;
    while(T--){
        solve();
    }

    return 0;
}