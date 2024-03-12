#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI=acos(-1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 0;//多组输入

void Solve() {
    cout << "请输入想生成随机数的个数n的值" << "\n";
    ll n; cin >> n;
    ll avg = 0, var = 0;
    vector<ll> a(n + 1);
    for(ll i = 1; i <= n; i ++ ) {
        a[i] = rand() % (201) + 100;
        avg += a[i];
    }
    cout << "生成的随机数为:";
    for(ll i = 1; i <= n; i ++ ) cout << a[i] << " ";
    avg /= n;
    for(ll i = 1; i <= n; i ++ ) {
        var += (a[i] - avg) * (a[i] - avg);
    }
    var /= n;
    cout << "生成随机数的平均值为" << avg << "\n";
    cout << "生成随机数的方差为" << var << "\n"; 
}


signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}