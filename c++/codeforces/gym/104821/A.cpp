#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long

const int N = 2e6 + 10;



void solve()
{
    int n,m;
    cin>>n>>m;
    vector<int> a(m+1),b(m+1);
    for(int i=1;i<=m;i++){
        cin>>a[i]>>b[i];
    }
    vector<int> p(m+1);
    iota(p.begin(),p.end(),0);
    sort(p.begin()+1,p.end(),[&](int x,int y){
        return a[x]<a[y];
    });
    int la=0;
    for(int i=1;i<=m;i++){
        int id=p[i];
        if(b[id]-b[p[i-1]]!=a[id]-a[p[i-1]]){
            if(a[id]-b[id]<a[p[i-1]]+1){
                cout<<"No\n";
                return ;
            }
            
        }
        // la=b[id]-la;
    }
    cout<<"Yes\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int testcase=1;
    cin>>testcase;
    while(testcase--){
        solve();
    }
}
