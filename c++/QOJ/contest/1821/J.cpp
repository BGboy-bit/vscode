#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
using PII = pair<int,int>;

constexpr ll INF = 2E18 + 10;
constexpr int N = 2E6 + 10;

bool cmp(PII a, PII b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

void solve()
{
    ll n, m, q; cin >> n >> m >> q;
    map<PII, ll> mp;
    vector<ll> st(n + 1, 0);
    vector<PII> ans(m + 1);
    ll nw = -1;
    for(ll i = 1; i <= m; i ++ ) {
        ans[i].first = i; ans[i].second = 0;
    }
    for(ll i = 1; i <= q; i ++ ) {
        ll ty; cin >> ty;
        if(ty == 1) {
            ll x; cin >> x;
            nw = x;
        } else {
            ll id, x; cin >> id >> x;
            if(x != nw || mp[{id, x}] == 1) continue;
            mp[{id, x}] = 1;
            if(ty == 2) {
                ans[id].second += m - st[x];
                st[x] ++ ;
            }
        }
    }
    sort(ans.begin() + 1, ans.end(), cmp);
    for(ll i = 1; i <= m; i ++ ) {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
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