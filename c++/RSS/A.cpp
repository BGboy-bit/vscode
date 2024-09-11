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
    if(fx==fy) return ;
    p[fy]=fx;
    siz[fx]+=siz[fy];
    // siz[fy]=0;
}

void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        p[i]=i;
        siz[i]=1;
    }

    vector<vector<char>> a(n+1,vector<char>(m+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }

    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            // if(p[(i-1)*m+j]!=(i-1)*m+j) continue;
            if(a[i][j]!='#') continue;
            if(i+1<=n&&a[i+1][j]=='#') {
                merge((i-1)*m+j,i*m+j);
            }
            if(j+1<=m&&a[i][j+1]=='#') {
                merge((i-1)*m+j,(i-1)*m+j+1);
            }
        }
    }
    int n1=0,n2=0,n3=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int t=(i-1)*m+j;
            if(find(t)!=t) continue;
            if(a[i][j]!='#') continue;
            // cout<<siz[t]<<"\n";
            // cout<<i<<" "<<j<<"\n";
            if(siz[t]==3) n1++;
            if(siz[t]==8) n2++;
            if(siz[t]==13) n3++;
        }
    }
    cout<<n1<<" "<<n2<<" "<<n3<<"\n";
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