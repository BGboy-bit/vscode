#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n, k; cin >> n >> k;
    if(k >= n) {
        cout << "1\n"; return ;
    }
    if(n % 2 == 0) {
        cout << (n + k / 2 * 2 - 1) / (k / 2 * 2) << "\n";
    } else {
        if(k % 2 == 1) {
            cout << (n - 2) / (k - 1) + 1 << "\n";
        } else {
            cout << n / k + 1 << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T; cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}