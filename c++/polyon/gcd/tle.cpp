#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n, K; cin >> n >> K;
    vector<ll> a(n + 1);
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i]; 
    } 
    ll gd = 0;
    ll ans1 = 0, ans2 = 0;
    for(ll k = 1; k <= K; k ++ ) {
        vector<ll> b(a);
        ll minn = 1e12;
        for(ll i = 1; i <= n; i ++ ) {
            b[i] += k;
            minn = min(minn, b[i]);
        }
        bool ac = 1;
        for(ll i = 1; i <= n; i ++ ) {
            if(b[i] % minn != 0) {
                ac = 0; break;
            }
        }
        if(ac) {
            ans1 ++ ; ans2 += k;
        }
    }
    cout << ans1 << " " << ans2 << "\n";
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