#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 1;//¶à×éÊäÈë

ll n;
ll a[MAX];

void Solve() {
    cin >> n;
    ll summ = 0;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
        summ += a[i];
    }
    if(summ == n) {
        if(n % 2 == 0) cout << "0" << "\n";
        else cout << "1" << "\n";
    }
    else cout << "499122177" << "\n";
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}