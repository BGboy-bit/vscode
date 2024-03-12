#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;

void Solve() {
    ll b, c, h;
    cin >> b >> c >> h;
    if(b >= c + h + 1 ) cout << (c + h) * 2 + 1 << "\n";
    else cout << b * 2 - 1 << "\n";    
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