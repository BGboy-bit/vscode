#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 5e5 + 10;
const int mod = 1e9 + 7;
ll a[N];
ll res = 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll q; cin >> q;
    while(q -- ) {
        ll t, v; cin >> t >> v;
        res -= t;
        a[res] = res * v;
        res ++ ;
        a[res - 1] = (a[res - 1] + a[res - 2]) % mod;
        cout << a[res - 1] << endl;
    }
    return 0;
}