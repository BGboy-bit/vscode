#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef double ld;

void Solve() {
    ll n, k; cin >> n >> k;
    vector<ld> a(n + 1);
    vector<ll> t(n + 1);
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
        a[i] /= 100.0;
    }
    sort(a.begin() + 1, a.end());
    priority_queue<pair<ld, ll>> q;
    for(ll i = 1; i <= n; i ++ ) {
        q.push({1.0 + a[i], i});
    }
    ll pos = n;
    while(k && pos > 1) {
        auto [cnt, idx] = q.top(); q.pop();
        t[idx] ++ ; k -- ;
        pos = min(pos, idx);
        cnt = (1.0 + (t[idx] + 1) * a[idx]) / (1.0 + t[idx] * a[idx]);
        q.push({cnt, idx});
    }
    ll x = max((k - 10) / n, 0); k -= x * n;
    // while(!q.empty()) q.pop(); 
    priority_queue<pair<ld, ll>> q1;
    for(ll i = 1; i <= n; i ++ ) {
        t[i] += x;
        q1.push({(1.0 + (t[i] + 1) * a[i]) / (1.0 + t[i] * a[i]), i});
    }
    while(k) {
        auto [cnt, idx] = q1.top(); q1.pop();
        t[idx] ++ ; k -- ;
        cnt = (1.0 + (t[idx] + 1) * a[idx]) / (1.0 + t[idx] * a[idx]);
        q1.push({cnt, idx});        
    }

    ld ans = 1;
    for(ll i = 1; i <= n; i ++ ) {
        ans *= 1.0 + a[i] * t[i];
    }
    cout << ans << "\n";
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
/*
2
3 5
50 100 50
10 1000000
1 2 3 4 5 6 7 8 9 10
*/