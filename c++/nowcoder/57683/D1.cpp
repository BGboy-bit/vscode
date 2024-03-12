#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 2e5 + 10;
ll n, k;
ll a[MAX], b[MAX];

ll calc(ll x) {
    ll cnt = 0;
    while(x % 10 == 0) {
        cnt ++;
        x /= 10;
    }
    return cnt;
}

void Solve() {
    cin >> n >> k;
    b[0] = 1;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
        b[i] = a[i] * b[i - 1]; 
    }

    ll ans = 0, L, R;
    for(ll i = 1; i <= n; i ++ ) {
        ll l = i, r = n;
        while(l < r) {
            ll mid = l + r >> 1;
            if(calc(b[mid] / b[i - 1]) >= k) r = mid;
            else l = mid + 1; 
        }
        L = l;
        l = i, r = n;
        while(l < r) {
            ll mid = l + r + 1 >> 1;
            if(calc(b[mid] / b[i - 1]) <= k) l = mid;
            else r = mid - 1;
        }
        R = r;
        if(calc(b[L] / b[i - 1]) == k) ans += R - L + 1;
    }
    cout << ans << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}