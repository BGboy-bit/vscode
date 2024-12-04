#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;

constexpr ll INF = 1e9 + 10;
constexpr int N = 2E6 + 10;

void solve()
{
    ll n; cin >> n;
    vector<ll> a(n + 1);
    ll maxx = -INF, minn = INF, ans = 0;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i]; 
        if(a[i] >= 0) minn = min(minn, a[i]);
        if(a[i] <= 0) maxx = max(maxx, a[i]);
        ans += abs(a[i]);
    }
    if(n == 1) {
        cout << a[1] << "\n"; return ;
    }
    if(minn == INF) ans += 2 * maxx;
    if(maxx == -INF) ans -= 2 * minn;
    cout << ans << "\n";
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