#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n; cin >> n;
    vector<ll> a(n + 1), d(n + 1), fa(n + 1), vis(n + 1);
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
        fa[i] = a[i];
    }
    ll ans = 0;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> d[i];
        if(!vis[d[i]]) {
            vis[d[i]] = 1;
            ll x = d[i], cnt = 1;
            while(!vis[fa[x]]) {
                vis[fa[x]] = 1;
                x = fa[x];
                cnt ++ ;
            }
            ans += cnt;
        }
        cout << ans << " \n"[i == n];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1; cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}