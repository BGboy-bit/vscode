#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll a, b, c; cin >> a >> b >> c;
    ll d = (a + b + c) / 3; 
    if((a + b + c) % 3 == 0 && a <= d && b <= d) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
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