#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

ll n, k; 
vector<pair<ld, ld>> node(100010);
const ld inf = 1e18 + 10;

bool check(ld x) {
    vector<ld> a(n + 1);
    for(ll i = 1; i <= n; i ++ ) {
        a[i] = node[i].second - x * node[i].first;
    }
    vector<ld> b(n + 1, inf);
    ll len = -1;
    for(ll i = 1; i <= n; i ++ ) {
        ll r = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        b[r] = a[i];
        len = max(len, r + 1);
    }
    return len >= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> node[i].first >> node[i].second;
    }
    ld l = -1e9, r = 1e9;
    ll T = 100;
    while(T -- ) {
        ld mid = (l + r) / 2;
        if(check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    } 
    cout << fixed << setprecision(6) << l << "\n";
    return 0;
}