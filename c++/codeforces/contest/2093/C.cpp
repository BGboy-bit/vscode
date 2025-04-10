#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool ispri(ll x) {
    if(x == 1) return false;
    if(x == 2 || x == 3) return true;
    for(ll i = 2; i * i <= x; i ++ ) {
        if(x % i == 0) {
            return false;
        }
    }
    return true;
}

void Solve() {
    ll x, k; cin >> x >> k;
    if(k == 1) {
        if(ispri(x)) {
            cout << "Yes\n"; 
        } else {
            cout << "No\n";
        }
    } else {
        if(x == 1) {
            ll x = 0;
            for(ll i = 1; i <= k; i ++ ) {
                x = x * 10 + 1;
            }
            if(ispri(x)) {
                cout << "Yes\n"; 
            } else {
                cout << "No\n";
            }
        } else {
            cout << "No\n";
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