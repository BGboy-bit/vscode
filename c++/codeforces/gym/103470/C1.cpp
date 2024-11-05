#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;

constexpr ll INF = 2E18 + 10;
constexpr int N = 2E6 + 10;

void solve()
{
    vector<ll> a(3e6 + 10);
    ll n, k; cin >> n >> k;
    ll ans = 0;
    for(ll i = 1; i <= n; i ++ ) {
        ll b; cin >> b; b += 2e6;
        a[b] ++ ;
        a[b + k] ++ ;
        a[b - k] -- ;
        ans = max(a[b], ans);
        ans = max(a[b + k], ans);
    }
    cout << ans << "\n";
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