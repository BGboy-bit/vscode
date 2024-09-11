#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll =long long;

constexpr int N = 2E6+10;

int p[N],siz[N];
int find(int x){
    if(x!=p[x]){
        p[x]=find(p[x]);
    }
    // while(p[x]!=x){
    //     p[x]=find(p[x]);
    // }
    return p[x];
}

void merge(int x,int y){
    int fx=find(x),fy=find(y);
    if(fx==fy)
    p[fy]=fx;
    siz[fx]+=siz[fy];
    // siz[fy]=0;
}

void solve()
{
    int n,m;
    cin>>n;
    for(int i=1;i<=n;i++){
        p[i]=i;
        siz[i]=1;
    }

    for(int i=1;i<=3;i++){
        int x,y;
        cin>>x>>y;
        merge(x,y);
    }
    for(int i=1;i<=n;i++){
        cout<<siz[find(i)]<<" ";
    }
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