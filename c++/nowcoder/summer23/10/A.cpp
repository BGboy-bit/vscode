#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef long double lb;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 1;//∂‡◊È ‰»Î

void Solve() {
    lb n, m;
    scanf("%lf %lf", &n, &m);
    lb x = 2 / n; 
    for(ll i = 1; i <= m; i ++ ) {
        x = x * x;
    }
    printf("%.15lf", x);
}


signed main() {
    ll T = 1;
    while(T --) {
        Solve();
    }
    return 0;
}