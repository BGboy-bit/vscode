#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;

db n;

void Solve() {
    scanf("%lf", &n);
    if(n != 2) printf("%.9lf 2.000000000\n", ((n - 1) * ((n - 2) * 2 + 1) + n - 1) / (n * (n - 1)));
    else printf("1.000000000 1.000000000\n");
}


int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    ll T = 1;
    // cin >> T;
    scanf("%ld", &T);
    while(T --) {
        Solve();
    }
    return 0;
}