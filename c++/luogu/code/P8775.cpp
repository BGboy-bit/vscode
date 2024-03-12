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

ll h[MAX];
ll n, x; 

bool ac(ll y) {
    //if(y == n) return true;
    ll sum = 0;
    for(ll i = 1; i <= y; i ++ ) {
        sum += h[i];
    } 
    if(2 * x > sum) return false;
    for(ll i = 1; i < n - y; i ++ ) {
        sum = sum - h[i] + h[i + y];
        if(2 * x > sum) return false; 
    }
    return true;
}

// void Solve1() {
//     cin >> n >> x;
//     for(ll i = 1; i < n; i ++ ) cin >> h[i];
//     ll l = 1, r = n;
//     while(l != r) {
//         ll mid = l + r >> 1;
//         if(ac(mid)) r = mid;
//         else l = mid + 1;
//     }
//     cout << l << "\n";
// }

void Solve2() {
    cin >> n >> x; x = x * 2; 
    for(ll i = 1; i < n; i ++ ) cin >> h[i];
    ll ans = 0;
    for(ll i = 1, j = 0, sum = 0; i < n; i ++ ) {
        while(j < n && sum < x) sum += h[++ j];
        ans = max(ans, j - i + 1);
        sum -= h[i]; 
    }
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    while(T -- ) {
        //Solve1();
        Solve2();
    }
    return 0;
}