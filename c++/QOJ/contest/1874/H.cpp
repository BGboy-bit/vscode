#include<bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
using pii = pair<int,int>;

constexpr ll N = 2E6 + 10, INF = 2E18 + 10;

void solve()
{
    ll n; cin >> n;
    vector<ll> a(n + 1);
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
    }
    ll ans = 0, kk = 0;
    for(ll i = 2; i <= n - 1; i ++ ) {
        if(a[i] > a[i - 1] && a[i] > a[i + 1]) {
            ans ++ ;
            if((i == 2 || i > 2 && (a[i - 1] <= a[i - 2] || a[i - 1] <= a[i + 1])) && 
            (i == n - 1 || i < n - 1 && (a[i + 1] <= a[i - 1] || a[i + 1] <= a[i + 2]))) {
                kk = max(kk, 1ll);
            }
            if(i - 3 <= n && a[i] == a[i + 2] && a[i + 2] > a[i + 1] && a[i + 2] > a[i + 3]) {
                kk = max(kk, 2ll);
            }
        }
    }
    cout << ans - kk << "\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
}