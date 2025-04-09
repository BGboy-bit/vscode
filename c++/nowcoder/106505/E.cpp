#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll pr(ll x) {
    vector<ll> pri;
    for(ll i = 2; i <= x; i ++ ) {
        if(x % i == 0) {
            return i;
        }
    }
    return 0;
}

vector<ll> PR;

void Solve() {
    ll n; cin >> n;
    vector<ll> a(n + 1);
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
    }
    if(a[1] == 1 || a[n] == 1) {
        cout << "-1\n"; return ;
    }
    if(gcd(a[1], a[n]) != 1) {
        cout << "1\n";
        cout << 1 << " " << n << "\n"; 
        return ;
    }

    ll x1 = pr(a[1]); ll x2 = pr(a[n]);
    ll x = x1 * x2;
    if(x <= n) {
        for(ll i = 1; i <= n; i ++ ) {
            if(a[i] == x) {
                cout << "2\n";
                cout << 1 << " " << i << " " << n << "\n";
                return ;
            }
        }
    } 
    for(auto y : PR) {
        if(y != x1 && y * x1 <= n && y != x2 && y * x2 <= n) {
            ll y1 = y * x1, y2 = y * x2;
            ll pos1, pos2;
            for(ll i = 1; i <= n; i ++ ) {
                if(a[i] == y1) pos1 = i;
                if(a[i] == y2) pos2 = i;
            }
            cout << "3\n";
            cout << 1 << " " << pos1 << " " << pos2 << " " << n << "\n";
        }
        if(y * x1 > n || y * x2 > n) {
            cout << "-1\n"; return ;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1; cin >> T;
    vector<ll> b(100010);
    for(ll i = 2; i <= 100000; i ++ ) {
        if(b[i] == 0) {
            b[i] = 1; PR.push_back(i);
            for(ll j = i; j <= 100000; j += i) b[i] = 1; 
        }
    }
    while(T -- ) {
        Solve();
    }
    return 0;
}










