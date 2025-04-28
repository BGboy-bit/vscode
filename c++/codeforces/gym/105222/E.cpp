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
                if(j+1<=m && a[i][j+1]=='L'&&b[i][j+1]!=-1){
                    b[i][j]=b[i][j+1];
                }else if(j-1>=1 && a[i][j-1]=='R'&&b[i][j-1]!=-1){
                    b[i][j]=b[i][j-1];
                }else if(i-1>=1 && a[i-1][j]=='D'&&b[i-1][j]!=-1){
                    b[i][j]=b[i-1][j];
                }else if(i+1<=n && a[i+1][j]=='U'&&b[i+1][j]!=-1){
                    b[i][j]=b[i+1][j];
                }else if(b[i][j]==-1){
                    b[i][j]=++tot;
                }
                else{
                    // cerr<<i<<" "<<j<<"\n";
                    // for(int i1=1;i1<=n;i1++){
                    //     for(int j1=1;j1<=m;j1++){
                    //         cerr<<b[i1][j1]<<" \n"[j1==m];
                    //     }
                    // }
                    assert(0);
                   cout<<"No\n";
                   return ; 
                }
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
            // cout<<i<<" "<<j<<"\n";
        }
    }
    map<int,vector<pii>> cnt;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==1&&j==m) continue;
            // cout<<b[i][j]<<" ";
            cnt[b[i][j]].push_back({i,j});
        }
        // cout<<"\n";
    }
    int sz=0;
    for(auto&[x,y] : cnt){
        sz++;
        // cout<<y<<"\n";
        if(y.size()!=3){
            cout<<"No\n";
            return ;
        }
        sort(y.begin(),y.end());
        // for(auto [f,s] : y){
        //     cout<<f<<" "<<s<<"\n";
        // }
        vector<int> po={0,1,2};
        bool ok=0;
        do{
            if(y[po[0]].first==y[po[1]].first&&abs(y[po[0]].second-y[po[1]].second)==1
            &&
                y[po[1]].second==y[po[2]].second&&abs(y[po[1]].first-y[po[2]].first)==1
            &&
                abs(y[po[0]].first-y[po[2]].first)==1&&abs(y[po[0]].second-y[po[2]].second)==1){
                    ok=1;
                    break;
                }
        }while(next_permutation(po.begin(),po.end()));
        if(!ok){
            cout<<"No\n";
            return ;
        }
    }
    // cout<<"OK\n";
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
    cin>>T;
    while(T--){
        solve();
    }

    return 0;
}