#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;

constexpr ll INF = 2E18 + 10;
constexpr int N = 2E6 + 10;
int p[N];
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<ll> a(n + 1), b(m + 1);
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
    }
    for(ll i = 1; i <= m; i ++ ) {
        cin >> b[i];
    }
    sort(a.begin() + 1, a.end());
    sort(b.begin() + 1, b.end());
    ll pos = lower_bound(a.begin(), a.end(), b[1]) - a.begin();
    ll ans = max(pos - 1, 0ll);
    for(ll i = 1; i < m; i ++ ) {
        ll pos1 = upper_bound(a.begin(), a.end(), b[i]) - a.begin();
        ll pos2 = lower_bound(a.begin(), a.end(), b[i + 1]) - a.begin();
        ans = max(ans, pos2 - pos1);
    }
    pos = upper_bound(a.begin(), a.end(), b[m]) - a.begin();
    ans = max(ans, n - pos + 1);
    if(!ans) {
        cout << "Impossible\n"; return ;
    }
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