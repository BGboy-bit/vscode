#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
using PII = pair<int,int>;

constexpr ll INF = 2E18 + 10;
constexpr int N = 2E6 + 10;

void solve()
{
    int n,a,b;
    // cin>>n>>a>>b;
    // cin >> b; n = b;
    a = 3, b = 7;
    for(ll n = 1; n <= b; n ++ ) {
   if(a==b){
        cout<<n<<'\n';
        return ;
    }
    if(a==0){
        cout<<1ll<<'\n';
        return ;
    }
    int x=0,y=0;
    string s;
    for(int i=1;i<=n;i++){
        if(x*b<=a*y){
            s=s+'1';
            x++;
            y++;
        }else {
            // cout<<'0';
            s=s+'0';
            y++;
        }
    }
    int xx=0;
    for(int i=2;i<n;i++){
        if(s[i]=='0')break;
        xx++;
    }
    s = s.substr(2, s.size() - 2);
    cout<<s<<'\n';

    // cout<<xx<<'\n';
    }
 
}

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr), cout.tie(nullptr);

    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
}