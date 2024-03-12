#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



void Solve() {
    queue<ll> q;
    ll n, k, x;
    cin >> n >> k >> x;
    if(x != 1) {
        cout << "YES" << "\n" << n << "\n";
        while(n -- ) cout << "1 ";
        cout << "\n"; 
    }
    else if(k == 1) cout << "NO" << "\n";
    else if(n % 2 == 0) {
        cout << "YES" << "\n" << n / 2 << "\n";
        while(n != 0) {
            n -= 2;
            cout << "2 ";
        }
        cout << "\n"; 
    }
    else {
        if(k == 2) cout << "NO" << "\n";
        else {
            cout <<"YES" << "\n" << (n - 3) / 2 + 1 << "\n" << "3 ";
            n -= 3;
            while(n != 0) {
                n -= 2;
                cout << "2 ";
            }
            cout << "\n"; 
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tt;
    cin >> tt;
    while(tt -- ) {
        Solve();
    }
    return 0;
}