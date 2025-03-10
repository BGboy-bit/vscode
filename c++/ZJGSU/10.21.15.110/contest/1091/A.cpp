#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct val {
    ll x, y;
    bool operator <(const val &b) const {
        return x < b.x;
    } 
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll n, k; cin >> n >> k;
    string s; cin >> s; s = "!" + s;
    vector<ll> a(n + 1);
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
    }
    priority_queue<val> pq;
    ll cnt = 0;
    for(ll i = 1; i <= n; i ++ ) {
        if(s[i] == '0') {
            cnt += a[i];
        } else {
            if(cnt == 0) {
                pq.push({(a[i] + 1) / 2, 0});
            } else {
                if(cnt < a[i]) {
                    pq.push({(a[i] + cnt + 1) / 2, (a[i] + 1) / 2 + cnt - (a[i] + cnt + 1) / 2});
                } else {
                    pq.push({cnt, 0}); pq.push({(a[i] + 1) / 2, 0});
                }
               cnt = 0;
            }
        }
    }
    if(s[n] == '0') pq.push({cnt, 0});
    ll ans = 0;
    while(!pq.empty() && k > 0) {
        val v = pq.top(); pq.pop();
        ll x = v.x, y = v.y;
        if(y != 0) {
            pq.push({y, 0});
        }
        ans += x; k -- ;
    }
    cout << ans << "\n";
    return 0;
}