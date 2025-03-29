#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n; cin >> n;
    map<ll, ll> a, b;
    ll cnt1 = 0, cnt2 = 0;
    for(ll i = 1; i <= n; i ++ ) {
        ll x; cin >> x;
        if(!a.count(x)) {
            a[x] = 1; cnt1 ++ ;
        }
    } 
    for(ll i = 1; i <= n; i ++ ) {
        ll x; cin >> x;
        if(!b.count(x)) {
            b[x] = 1; cnt2 ++ ;
        }
    }
    if(cnt1 + cnt2 >= 4) {
        cout << "Yes\n"; return ;
    } else {
        cout << "No\n"; return ;
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