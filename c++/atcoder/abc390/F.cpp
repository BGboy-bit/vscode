#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    ll a;
    ll ndp = 0, dp = 0, ans = 0;
    vector<ll> vis(n + 2);
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a;
        ndp = dp + i - vis[a];
        if(vis[a - 1] > vis[a]) ndp -= vis[a - 1] - vis[a];
        if(vis[a + 1] > vis[a]) ndp -= vis[a + 1] - vis[a];
        vis[a] = i;
        ans += ndp; dp = ndp;
    }
    cout << ans << "\n";
    return 0;
}