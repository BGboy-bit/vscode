#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;

ll n, r, g, b;

void Solve() {
    cin >> n >> r >> g >> b;
    if(n & 1) {
        if((r + g + b - 1) & 1) cout << "Alice" << "\n";
        else cout << "Bob" << "\n"; 
    }
    else cout << "Alice" << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}