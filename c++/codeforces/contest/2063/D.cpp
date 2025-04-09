#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n, m; cin >> n >> m;
    vector<ll> a(n + 1), b(m + 1);
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
    } 
    for(ll i = 1; i <= m; i ++ ) {
        cin >> b[i];
    } 
    sort(a.begin() + 1, a.end());
    sort(b.begin() + 1, b.end());
    vector<ll> a1(n / 2 + 1), b1(m / 2 + 1);
    ll cnt1 = 0, cnt2 = 0;
    for(ll i = 1; i <= n / 2; i ++ ) {
        a1[i] = a[n - i + 1] - a[i];
        cnt1 += a[n - i + 1] - a[i];
    }
    for(ll i = 1; i <= m / 2; i ++ ) {
        b1[i] = b[m - i + 1] - b[i];
        cnt2 += b[m - i + 1] - b[i];
    }
    if(n > m) {
        ll x = min(n / 2, m);
        cout << x << "\n";
        for(ll i = 1; i <= x; i ++ ) {
            cout << a1[i] << " \n"[i == x]; 
        }
        return ;
    } else if(n < m) {
        ll x = min(m / 2, n);
        cout << x << "\n";
        for(ll i = 1; i <= x; i ++ ) {
            cout << b1[i] << " \n"[i == x]; 
        }
        return ;
    } else {
        ll x = n / 2;
        cout << x << "\n";
        if(cnt1 >= cnt2) {
            for(ll i = 1; i <= x; i ++ ) {
                cout << a1[i] << " \n"[i == x]; 
            }
            return ;
        } else {
            for(ll i = 1; i <= x; i ++ ) {
                cout << b1[i] << " \n"[i == x]; 
            }
            return ;
        }
    }
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