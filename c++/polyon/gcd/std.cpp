#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n + 1);
    ll minn = 1000000;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i]; minn = min(a[i], minn);
    } 
    ll gd = 0;
    for(ll i = 1; i <= n; i ++ ) {
        gd = __gcd(gd, a[i] - minn);
    }
    if(gd == 0) {
        cout << k << " " << k * (k + 1) / 2 << "\n"; 
        return ;
    }
    ll ans1 = 0, ans2 = 0;
    for(ll i = 1; i * i <= gd; i ++ ) {
        if(gd % i == 0) {
            if(minn + k >= i && minn < i) {
                ans1 ++ ; ans2 += i - minn;
            } 
            if(gd / i != i) {
                ll x = gd / i;
                if(minn + k >= x && minn < x) {
                    ans1 ++ ; ans2 += x - minn;
                }
            }
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