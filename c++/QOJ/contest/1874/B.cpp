#include<bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
using pii = pair<int,int>;

constexpr ll N = 2E6 + 10, INF = 2E18 + 10;

ll n, x, y;
ll x1, y3;

void solve()
{
    cin >> n >> x >> y;
    x1 = 0, y3 = 0;
    vector<ll> b(n + 1), a;
    a.push_back(-1);
    map<ll, ll> mp;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> b[i];
        if(!mp.count(b[i])) {
            mp[b[i]] = a.size();
            a.push_back(b[i]);   
        }
        x1 += i * b[i];
        y3 += i * b[i] * b[i];
    }
    ll m = a.size() - 1;
    vector<vector<ll>> pos(m + 1);
    for(ll i = 1; i <= n; i ++ ) {
        pos[mp[b[i]]].push_back(i);
    }
    ll x2 = x - x1, y2 = y - y3;
    if(!x2 && y2 || x2 && !y2 || x2 && y2 % x2 != 0 || x2 < 0 && y2 > 0 || x2 > 0 && y2 < 0) {
        cout << "0\n"; return ;
    }
    ll ans = 0;
    if(x2 == 0) {
        for(ll i = 1; i <= 100000; i ++ ) {
            if(mp.count(i)) {
                ll pss = pos[mp[i]].size();
                if(pss >= 2) {
                    ans += pss * (pss - 1) / 2;
                }    
            }
        }
        cout << ans << "\n";
        return ;
    }
    ll z = y2 / x2;
    for(ll i = 1; i <= n; i ++ ) {
        ll aj = abs(z - b[i]);
        if(aj == b[i]) continue;
        ll k = x2 / (b[i] - aj);
        if(k < 0) continue;
        if(i + k <= n && b[i + k] == aj) {
            ans ++ ;
        }
    }
    cout << ans << "\n";
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