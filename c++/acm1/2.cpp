#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 0;//∂‡◊È ‰»Î

void Solve() {
    for(ll i = 1; i <= 20; i ++ ) {
        ll sum1 = i * i + 1;
        for(ll j = 2; j <= i; j ++ ) {
            for(ll k = 2; k <= i; k ++ ) {
                ll sum2 = j * j + k * k;
                if(sum2 > sum1) break;
                else if(sum2 == sum1) cout << i << " " << j << " " << k << "\n";
            }
        }
    }
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