#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using ll = long long;
#define INF 2000000000000000000
#define dbINF DBL_MAX/*DBL_MAX,DBL_MIN,INT_MAX,INT_MIN*/
#define y1 Y1
#define y2 Y2
#define debug(a) cout<<#a<<"="<<a<<'\n';
#define PI acos(-1)/*3.141592653589*/
using namespace std;
/*----------------------------------------------*/
#define int long long
template<class T>
map<T,int> sortMap(const map<T,int> mp){vector<pair<T,int>> v(mp.begin(),mp.end());sort(v.begin(),v.end(),[&](auto x,auto y){
        return x.second<y.second;
});map<T,int> ans;for(auto [lo,v]:v){ans[lo]=v;}return ans;
}
const double eps = 1e-10;
typedef array<int,2> PII;
//const int mod=1e9;

const int N = 1e6 + 10;
/*----------------------------------------------*/
// int f[2][N];
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<int> x(n+1),y(n+1);
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
    }
    // for(int i=0;i<=1;i++){
    //     for(int j=0;j<=m+1;j++){
    //         f[i][j]=INF;
    //     }
    // }
    vector<vector<int>> f(2,vector<int>(m+1,INF));
    f[0][0]=0;
    for(int i=1;i<=n;i++){
        // debug(f[1][22])debug(f[1][28])
        // debug(f[0][16])debug(f[1][22])
        auto dp=f;
        for(int j=m;j>=x[i];j--){
            f[0][j]=min(f[0][j],dp[0][j-x[i]]+y[i]);
            f[1][j]=min(f[1][j],dp[1][j-x[i]]+y[i]);
        }
        for(int j=m;j>=x[i]*2;j--){
            f[1][j]=min(f[1][j],dp[0][j-x[i]*2]+y[i]/2);
        }
        for(int j=0;j<=m;j++){
            cout<<f[0][j]<<" "<<f[1][j]<<"\n";
        }
        cout<<"\n\n";
        dp=f;
    }
    // cout<<f[0][m]<<" "<<f[1][m]<<"\n";
    cout<<min(f[0][m],f[1][m]);
}

/*----------------------------------------------*/	
signed main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

	// cout<<fixed<<setprecision(10);
    int testcase=1;
	// cin>>testcase;
    while(testcase--){
    	solve();
	}
}