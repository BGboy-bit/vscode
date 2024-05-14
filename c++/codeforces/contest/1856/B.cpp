#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 1e5 + 10;
bool multi = 1;//¶à×éÊäÈë

ll n;
ll a[MAX], b[MAX];

void Solve() {
    cin >> n;
    ll ans = 0;
    ll summ = 0;
    ll cnt = n;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
        summ += a[i];
        if(a[i] == 1) {
            ans += 2; cnt -- ;
        }
    }
    if(summ - ans < cnt || n == 1) cout << "No" << "\n";
    else cout << "Yes" << "\n";
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