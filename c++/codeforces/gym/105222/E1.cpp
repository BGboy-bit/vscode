#include<bits/stdc++.h>
#define int long long
using namespace std;

using ll = long long;
using pii = pair<int,int>;

constexpr ll N =2E6 + 10, inf = 2E18 + 10;

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>> a(n+1,vector<char>(m+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }

    if(a[1][m]!='.'){cout<<"No\n";return ;}

    int tot=0;
    vector<vector<int>> b(n+1,vector<int>(m+1,-1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]=='.') continue;
            if(a[i][j]=='C'){
                b[i][j]=++tot;
            }else{
                if(a[i][j]=='U'){
                    if(i-1>=1&&a[i-1][j]=='C'){
                        if(b[i-1][j]==-1){
                            b[i-1][j]=++tot;
                        }
                        b[i][j]=b[i-1][j];
                    }else{
                        cout<<"No\n";
                        return ;
                    }
                }else if(a[i][j]=='D'){
                    if(i+1<=n&&a[i+1][j]=='C'){
                        if(b[i+1][j]==-1){
                            b[i+1][j]=++tot;
                        }
                        b[i][j]=b[i+1][j];
                    }else{
                        cout<<"No\n";
                        return ;
                    }

                }else if(a[i][j]=='L'){
                    if(j-1>=1&&a[i][j-1]=='C'){
                        if(b[i][j-1]==-1){
                            b[i][j-1]=++tot;
                        }
                        b[i][j]=b[i][j-1];
                    }else{
                        cout<<"No\n";
                        return ;
                    }
                }else if(a[i][j]=='R'){
                    if(j+1<=m&&a[i][j+1]=='C'){
                        if(b[i][j+1]==-1){
                            b[i][j+1]=++tot;
                        }
                        b[i][j]=b[i][j+1];
                    }else{
                        cout<<"No\n";
                        return ;
                    }
                }else{
                    assert(0);
                }
            }

        }
    }
    map<int,int> cnt;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cnt[b[i][j]]++;
        }
    }
    int sz=0;
    for(auto&[x,y] : cnt){
        sz++;
        if(y!=3){
            cout<<"No\n";
            return ;
        }
    }
    if(sz*3+1!=n*m){
        cout<<"No\n";
        return ;
    }
    cout<<"Yes\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }

    return 0;
}