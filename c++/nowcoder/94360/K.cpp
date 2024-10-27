#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
typedef double db;
using PII = pair<int,int>;

constexpr ll INF = 2E18 + 10;
constexpr int N = 2E6 + 10;

struct node {
    ll x, y, z;
};

void solve()
{
    ll n,a,b;
    cin>>n>>a>>b;
    // n = 100000; a = 1231231; b = 1231231231;  
    ll ans1 = (n * a / b), ans2 = ans1 + 1;
    queue<node> q;
    ll sum1 = 1, sum2 = 1;
    q.push((node){ans1, n, ans1}); q.push((node){ans2, n, ans2});
    while(!q.empty()) {
        ll x = q.front().x, y = q.front().y, z = q.front().z; q.pop();
        if(z == ans1) sum1 -- ;
        if(z == ans2) sum2 -- ;
        ll x1 = (n - 1) * a / b, x2 = x1 + 1;
        if(x1 <= x - 1 && x - 1 <= x2 && (x - 1) * b <= a * (n - 1)) {
            q.push((node){x - 1, n - 1, z});
            if(z == ans1) sum1 ++ ;
            if(z == ans2) sum2 ++ ;
        }
        if(x1 <= x && x <= x2 && x * b > a * (n - 1)) {
            q.push((node){x, n - 1, z});
            if(z == ans1) sum1 ++ ;
            if(z == ans2) sum2 ++ ;
        }        
        if(sum1 == 0) {
            cout << ans2 << "\n"; return ;
        }
        if(sum2 == 0) {
            cout  << ans1 << "\n"; return ;
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int T=1e5;
    cin>>T;
    while(T--){
        solve();
    }
}