#include<bits/stdc++.h>
#define int long long
using namespace std;

using ll = long long;
using pii = pair<int,int>;

constexpr ll N =2E6 + 10, inf = 2E18 + 10;

struct node {
    ll x, y, pos;
};

bool cmp(node a, node b) {
    if(a.x == b.x) {
        return a.y < b.y;
    } else {
        a.x < b.x;
    }
}

void solve()
{
    ll n, q; cin >> n >> q;
    vector<ll> a(n + 1), b;
    map<ll, ll> mp;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
        mp[a[i]] ++ ;
        if(mp[a[i]] == 1 && i < n) {
            b.push_back(a[i]);
        }
    }
    vector<pair<ll, ll>> p[b.size() + 1];
    sort(b.begin(), b.end());
    for(ll i = 1; i < n; i ++ ) {
        p[mp[a[i]]].push_back({a[i + 1], i});
    }
    while(q -- ) {
        ll x, y; cin >> x >> y;
        ll z = x ^ y;
        ll pos1 = upper_bound(b.begin(), b.end(), z) - b.begin() - 1;
        for(ll i = 1; i <= )
        ll l = 0, r = n - 2;
        while(l < r) {
            ll mid = l + r + 1 >> 1;
            if(p[mid].x > z) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }
        ll pos1 = l;
        
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

    return 0;
}