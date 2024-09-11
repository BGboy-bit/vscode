#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
typedef array<ll, 2> PII; // vector<PII> a(n+1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 1;

void Solve() {
    db x1, x2, y1, y2; scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
    db ans1 = sqrt((x1 + x2) * (x1 + x2) + abs(y1 - y2) * abs(y1 - y2));
    db ans2 = sqrt(abs(x1 - x2) * abs((x1 - x2)) + (y1 + y2) * (y1 + y2)); 
    printf("%.10lf\n", min(ans1, ans2));    
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}