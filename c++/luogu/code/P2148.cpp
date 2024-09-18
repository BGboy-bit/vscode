// P2148 [SDOI2009] E&D
// https://www.luogu.com.cn/problem/P2148

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PII;

map<PII, ll> sg;

void SG() {
    for(ll i = 1; i <= 100; i ++ ) {
        for(ll j = 1; j <= i; j ++ ) {    
            set<ll> s;
            for(ll k = (i + 1) / 2; k < i; k ++ ) {
                s.insert(sg[{k, i - k}]);
            }
            for(ll k = (j + 1) / 2; k < j; k ++ ) {
                s.insert(sg[{k, j - k}]);
            }
            while(s.find(sg[{i, j}]) != s.end()) {
                sg[{i, j}] ++ ;
            }
        }
    }
    cout << "  ";
    for(ll i = 1; i <= 9; i ++ ) {
        cout << i << " \n"[i == 9];
    }
    for(ll i = 1; i <= 9; i ++ ) {
        cout << i << " ";
        for(ll j = 1; j <= 9; j ++ ) {
            cout << sg[{max(j, i), min(i, j)}] << " \n"[j == 9];
        }
    }
}

void Solve() {
    ll n; cin >> n;
    ll ans = 0;
    for(ll i = 1; i <= n / 2; i ++ ) {
        ll x, y; cin >> x >> y;
        ll z = (x - 1) | (y - 1);
        ll cnt = 0;
        while(z & 1) {
            cnt ++ ; z >>= 1;
        }
        ans ^= cnt;
    }
    if(ans) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // SG();
    ll T = 1; cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}