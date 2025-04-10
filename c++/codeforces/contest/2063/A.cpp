#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll l, r; cin >> l >> r;
    if(l == r && l == 1) {
        cout << "1\n"; return ;
    }
    cout << r - l << "\n";
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