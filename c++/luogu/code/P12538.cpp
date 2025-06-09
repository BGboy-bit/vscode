#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 5;
const int mod = 998244353;

map<pair<ll, ll>, ll> mp[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    vector<ll> a(n + 1); 
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
    }
    mp[0][{-1, -1}] = 1;
    for(ll i = 1; i <= n; i ++ ) {
        for(auto [pr, cnt] : mp[i - 1]) {
            auto [l, r] = pr;
            mp[i][{r, a[i]}] = (mp[i][{r, a[i]}] + cnt) % mod;
            if(abs(a[i] - r) == 1) {
                mp[i][{a[i], r}] = (mp[i][{a[i], r}] + cnt) % mod;
                if(abs(a[i] - l) == 1) {
                    mp[i][pr] = (mp[i][pr] + cnt) % mod;
                }
            }
        }
    }
    ll ans = 0;
    for(auto [_, cnt] : mp[n]) {
        ans = (ans + cnt) % mod;
    }
    cout << ans << "\n";
    return 0;
}