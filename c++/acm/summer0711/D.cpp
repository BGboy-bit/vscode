#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int MAX = 1e5 + 10;
ll n;
ll a[MAX];

void Solve() {
    cin >> n;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
    }
    for(ll i = 1; i <= n; i ++ ) {
        if(a[i] < 0) {
            ll cnt = 0;
            ll ris;
            for(ll j = i; j <= n; j ++ ) {
                if(a[j] > 0) {
                    ris = j - 1;
                    break;
                }
                else cnt += a[j];
                if(j == n) ris = j;
            }
        }
        for(ll i = 1;)
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    // cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}