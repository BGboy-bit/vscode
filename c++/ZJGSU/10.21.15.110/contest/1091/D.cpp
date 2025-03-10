#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N = -100000010;

struct ey {
    ll t, len, w;
};

bool cmp(ey a, ey b) {
    if(a.t == b.t) {
        return a.len < b.len;
    } else {
        return a.t < b.t;
    }
}

ll x, y, z, h, l;
ll ins(ll a, ll b, ll c) {
    if(z - c < 0 || z - c > h || (z - c) * (z - c) * l * l - h * h * 
    ((a - x) * (a - x) + (b - y) * (b - y) + (c - z) * (c - z)) < 0) {
        return -1;
    } else {
        return ((a - x) * (a - x) + (b - y) * (b - y) + (c - z) * (c - z));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> x >> y >> z >> h >> l;
    ll n; cin >> n;
    vector<ey> e;
    for(ll i = 1; i <= n; i ++ ) {
        ll t, a, b, c, w; cin >> t >> a >> b >> c >> w;
        ll len = ins(a, b, c);
        if(len != -1) {
            e.push_back({t, len, w});
        }
    }
    ll q; cin >> q;
    for(ll i = 1; i <= q; i ++ ) {
        ll T; cin >> T;
        e.push_back({T, N, i});
    }
    sort(e.begin(), e.end(), cmp);
    vector<pair<ll, ll>> ans(q + 1);
    ll res = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    ll cnt = 0, sum = 0, tim = 0;
    for(auto e1 : e) {
        ll t = e1.t;
        while(!pq.empty() && tim < t) {
            pair<ll, ll> p1 = pq.top(); pq.pop();
            ll d1 = p1.first, w1 = p1.second;
            ll tt = (w1 + 49) / 50;
            if(tim + tt <= t) {
                cnt ++, sum += w1;
                tim += tt;
            } else {
                sum += (t - tim) * 50;
                w1 -= (t - tim) * 50;
                pq.push({d1, w1});
                tim = t;
            }
        }
        tim = t;
        if(e1.len == N) {
            ans[e1.w] = {cnt, sum};
        } else {
            pq.push({e1.len, e1.w});
        }
    }
    for(ll i = 1; i <= q; i ++ ) {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
    return 0;
}