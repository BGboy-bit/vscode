#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
using db = long double;
constexpr ll INF = 2E18 + 10;
constexpr int N = 2E6 + 10;
constexpr db eps = 1e-8;
constexpr db inf = 10000;
db n, m, p; 
db f(db t) {
    return (n * t + m) / ((db)1 - pow(((db)1 - p / (db)10000), t)); 
}

void solve()
{
    cin >> n >> m >> p;
    if(p == inf) {
        cout << n + m << "\n"; return ;
    }
    db t;
    db l = 1, r = 1e9;
    while(r - l > eps) {
        db d = (r - l) / 3.0;
        db mid1 = l + d, mid2 = r - d;
        if(f(mid1) < f(mid2)) r = mid2;
        else l = mid1;
    }
    cout << fixed << setprecision(10);
    cout << min(f(ceil(l)), f(ceil(l) - 1)) << "\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
}