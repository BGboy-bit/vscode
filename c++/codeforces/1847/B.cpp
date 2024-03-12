#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int MAX = 2e5 + 10;
ll n;
ll a[MAX];
ll b[41];
ll f[41];

void Solve() {
    cin >> n;
    memset(f, 0, sizeof(f));
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
        for(ll j = 40; j >= 0; j -- ) {
            if((a[i] & b[j]) == 0) {
                if(f[j] == 1 || f[j] == 0) 
                f[j] += 2;
            }           
            else {if(f[j] == 2 || f[j] == 0) f[j] += 1;}
        }
    }
    bool gg = 0;
    for(ll i = 0; i <= 40; i ++ ) {
        if(f[i] == 1) {
            gg = 1;
            break; 
        }
    }
    if(gg) cout << 1 << "\n";
    else {
        ll ans = 0;
        ll x = b[40] - 1;
        for(ll i = 1; i <= n; i ++ ) {
            if((x & a[i]) == 0) {
                ans ++;
                if(i < n) x = b[40] - 1;
            }
            else x = (x & a[i]);
        }
        cout << ans << "\n";
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    b[0] = 1;
    for(ll i = 1; i <= 40; i ++ ) b[i] = b[i - 1] * 2;
    ll T = 1;
    cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}