#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;

constexpr ll INF = 2E18 + 10;
constexpr int N = 1E6 + 10;
constexpr int M = 1E3 + 10;
int m;
struct D{
    int l,r,d,u;
} a[N];

int ans[M+1][M+1];

void dfs(int t,int x,int y,bool dr){
    ans[x][y]=t;
    if(dr){
        if(y<m){
            dfs(a[t].r,x,y+1,dr);
        }else if(x<m){
            dfs(a[t].d,x+1,y,!dr);
        }else{
            return ;
        }
    }else{
        if(y>1){
            dfs(a[t].l,x,y-1,dr);
        }else if(x<m){
            dfs(a[t].d,x+1,y,!dr);
        }else{
            return ;
        }
    }
}

void solve()
{   
    cin>>m;
    int st=-1;
    for(int i=1;i<=m*m;i++){
        cin>>a[i].u>>a[i].d>>a[i].l>>a[i].r;
        if(a[i].u==-1&&a[i].l==-1){
            ans[1][1]=i;
            st=i;
        }
    }
    dfs(st,1,1,1);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            cout<<ans[i][j]<<" \n"[j==m];
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T = 1;
    // cin>>T;
    while(T--){
        solve();
    }
}