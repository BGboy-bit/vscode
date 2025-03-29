#include<bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
using pii = pair<int,int>;

constexpr ll N = 2E6 + 10, INF = 2E18 + 10;

void solve()
{
    int n;
    cin>>n;
    for(int i=n;;i++){
        if(i%7==0&&i%4!=0){
            cout<<i<<"\n";
            return ;
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
}