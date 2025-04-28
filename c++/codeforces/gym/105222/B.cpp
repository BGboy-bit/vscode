#include<bits/stdc++.h>
#define int long long
using namespace std;

using ll = long long;
using pii = pair<int,int>;

constexpr ll N =2E6 + 10, inf = 2E18 + 10;

void solve()
{
    vector<ll> a(6);
    for(ll i = 1; i <= 5; i ++ ) {
        cin >> a[i];
    }
    ll ans = 0;
    ans += a[3] / 2 + min(a[1], a[5]) + min(a[2], a[4]);
    ll x = min(a[1], a[5]), y = min(a[2], a[4]);
    a[1] -= x; a[5] -= x;
    a[2] -= y; a[4] -= y;
    a[3] %= 2;
    if(a[5] > 0) {
        for(ll i = 1; i < 5; i ++ ) {
            if(a[i] <= a[5]) {
                ans += a[i]; a[5] -= a[i]; 
                a[i] = 0; 
            } else {
                ans += a[5]; a[i] -= a[5];
                a[5] = 0; 
                break;
            }
        }
        if(a[5] > 0) {
            ans += a[5] / 2;
        }
    }
    if(a[4] > 0) {
        ll cnt = 0;
        for(ll i = 1; i < 4; i ++ ) {
            if((a[i] + cnt) / 2 <= a[4]) {
                ans += (a[i] + cnt) / 2; a[4] -= (a[i] + cnt) / 2;
                cnt = (a[i] + cnt) % 2; 
                a[i] = 0;
            } else {
                ans += a[4]; 
                a[i] -= (a[4] * 2 - cnt);
                cnt = 0; a[4] = 0;
                break;
            }
        }
        if(a[4] > 0) {
            ans += (a[4] + cnt) / 3;
        }
    }
    if(a[3] > 0) {
        if(a[2] > 0 && a[1] > 0) {
            ans ++ ; a[3] = 0; a[2] -- ; a[1] -- ;
        } else if(a[2] > 1) {
            ans ++ ; a[2] -= 2; a[3] = 0;
        } else if(a[1] > 2) {
            ans ++ ; a[1] -= 3; a[3] = 0;
        } else {
            a[1] ++ ; a[3] -- ;
        }
    }
    if(a[2] > 0) {
        ans += a[2] / 3;
        a[2] %= 3;
        if(a[1] >= 6 - a[2] * 2) {
            ans ++ ;
            a[1] -= 6 - a[2] * 2;
            a[2] = 0; 
        }
    }
    if(a[1] >= 6) {
        ans += a[1] / 6;
    }
    cout << ans << "\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    cin>>T;
    while(T--){
        solve();
    }

    return 0;
}