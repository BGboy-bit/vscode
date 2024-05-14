#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
typedef array<ll, 2> PII; // vector<PII> a(n+1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 0;


void Solve() {
    // vector<ll> ans;
    ll ans[MAX];
    ll cnt = 0;
    ll x = 1;
    ll a[62];
    a[0] = x;
    for(ll i = 1; i <= 60; i ++ ) {
        x *= 2;
        a[i] = x;
    }
    ll l, r; cin >> l >> r;
    while(l != r) {
        if(l == 0) {
            for(ll i = 0; i <= 60; i ++ ) {
                if(a[i] > r) {
                    // cout << 0 << " " << a[i - 1] << "\n";
                    ans[++ cnt] = 0;
                    ans[++ cnt] = a[i - 1];
                    l = a[i - 1];
                    break;
                }
            }
        } else {
            for(ll i = 0; i <= 60; i ++ ) {
                if(a[i] == l) {
                    if(r - l >= a[i]) {
                        //cout << l << " " << l + a[i] << "\n";
                        ans[++ cnt] = l;
                        ans[++ cnt] = l + a[i];
                        l = l + a[i];
                        break;
                    } else {
                        ll j = i - 1;
                        while(r - l < a[j]) j -- ;
                        //cout << l << " " << l + a[j] << "\n";
                        ans[++ cnt] = l;
                        ans[++ cnt] = l + a[j];
                        l = l + a[j];
                        break;
                    }
                }
                else if(a[i] > l) {
                    if(l % a[i - 1] == 0 && r - l >= a[i - 1]) {
                        //cout << l << " " << l + a[i - 1] << "\n";
                        ans[++ cnt] = l;
                        ans[++ cnt] = l + a[i - 1];
                        l = l + a[i];
                        break;
                    } else {
                        ll j = i - 2;
                        while(r - l < a[j] || l % a[j] != 0) j -- ;
                        //cout << l << " " << l + a[j] << "\n";
                        ans[++ cnt] = l;
                        ans[++ cnt] = l + a[j];
                        l = l + a[j];
                        break;
                    } 
                }
            }
        }
    }
    cout << cnt / 2 << "\n";
    for(ll i = 1; i <= cnt; i += 2) {
        cout << ans[i] << " " << ans[i + 1] << "\n";
    }
}


signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}