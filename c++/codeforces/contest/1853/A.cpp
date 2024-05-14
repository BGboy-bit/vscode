#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;

ll n;
ll a[MAX], b[MAX];

void Solve() {
    cin >> n;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
        if(i > 1) b[i - 1] = a[i] - a[i - 1];
    }
    sort(b + 1, b + n);
    if(b[1] < 0 ) cout << "0" << "\n";
    else {
        cout << b[1] / 2 + 1 << "\n";
    }
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