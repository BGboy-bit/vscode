#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m;

bool check(ll x, vector<ll> &a) {
    vector<ll> b(n + 1);
    for(ll i = 1; i <= n; i ++ ) {
        ll y = a[i];
        while(y >= x || b[y] > 0 && y > 0) y /= m;
        b[y] = 1;
    }
    for(ll i = 0; i < x; i ++ ) {
        if(!b[i]) return 0;
    }
    return 1;
}

void Solve() {
    cin >> n >> m;
    vector<ll> a(n + 1);
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    if (m == 1) {
        ll ans = 0;
        for (int i = 1; i <= n; i ++ )
        {
            if (a[i] == ans)
                ans ++ ;
        }
        cout << ans << "\n"; return ;
    }
    ll l = 1, r = n;
    while(l < r) {
        ll mid = l + r + 1 >> 1;
        if(check(mid, a)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << l << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1; //cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}