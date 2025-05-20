#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n, x; cin >> n >> x;
    vector<ll> a;
    for(ll i = 0; (1 << i) <= x; i ++ ) {
        if(x & (1 << i)) {
            a.push_back(i);
        }
    }
    if(a.size() >= n) {
        cout << x << "\n"; return ;
    }
    ll res = n - a.size(); 
    if(res % 2 == 1) {
        if(x > 1) {
            cout << x + res + 1 << "\n"; return ;
        } else {
            if(n >= 2) {
                cout << x + res + 3 << "\n"; return ;
            }
            else {
                cout << "-1\n"; return ;
            }
        }
    } else {
        cout << x + res << "\n";
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