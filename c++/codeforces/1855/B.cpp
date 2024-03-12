#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#include <random>
#include <chrono>
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;

vector<ll> v, v2;
long long n;
void Prime() {
    for(ll i = 1; i * i <= n; i ++ ) 
    if(n % i == 0) {
        v.push_back(i);
        if(n / i != i) v2.push_back(n / i);
    }
}


void Solve() {
    cin >> n;
    // Prime();
    // for(ll i = v2.size() - 1; i >= 1; i ++ ) {
    //     v.push_back(v2[i]);
    // }
    ll ans = 0;
    // for(ll i = 1; i < v.size(); i ++ ) {
    //     if(v[i] == v[i - 1] + 1) {
    //         ll cnt = 1;
    //         ll j;
    //         for(j = i; j < v.size(); j ++ ) {
    //             if(v[j] == v[j - 1] + 1) cnt ++ ;
    //             else break;
    //         }
    //         ans = max(cnt, ans);
    //         i = j;
    //     }
    // }
    for(ll i = 1; i <= n; i ++ ) {
        if(n % i == 0) ans ++ ;
        else break;
    }
    cout << ans << "\n"; 

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}