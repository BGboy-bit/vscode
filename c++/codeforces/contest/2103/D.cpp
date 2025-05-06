#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n; cin >> n;
    vector<ll> a(n + 1), cnt(n + 1);
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
        if(a[i] != -1) cnt[a[i]] ++ ;
    }
    vector<ll> b(n + 1);
    b[1] = n; b[2] = 1;
    ll res = b[1] - cnt[1];
    ll m = 2;
    for(ll i = 3; i <= n; i ++ ) {
        if(cnt[i] == 0) {
            m = i - 1; break;
        }
        if(i % 2 == 1) {
            b[i] = b[i - 2] - cnt[i - 2];
            res = b[i] - cnt[i];
        } else {
            b[i] = cnt[i - 2] + b[i - 2];
        }
    }
    vector<ll> d = b;
    bool ff = 1;
    for(ll i = 1; i <= n; i ++ ) {
        if(a[i] == -1) {
            cout << res << " \n"[i == n];
            ff = 0;
            for(ll i = 1; i < m - 1; i += 2) {
                b[i] = d[i + 2] + 1;
            }
            for(ll i = m / 2 * 2; i > 2; i -= 2) {
                b[i] = d[i - 2] + cnt[i - 2] + cnt[i] - 1;
            } 
            if(m % 2 == 1) {
                b[m] = d[m] - cnt[m] + 1;
            } else {
                b[m - 1] = d[m - 1] - cnt[m - 1] + 1;
            }
            b[2] = cnt[2];
        } else {
            if(ff)
                if(a[i] % 2 == 1)
                    cout << b[a[i]] -- << " \n"[i == n];
                else 
                    cout << b[a[i]] ++ << " \n"[i == n];
            else 
                if(a[i] % 2 == 1)
                    cout << b[a[i]] ++ << " \n"[i == n];
                else 
                    cout << b[a[i]] -- << " \n"[i == n];
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