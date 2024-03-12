#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;

ll n;
ll p[MAX];

void Solve() {
    cin >> n;
    ll cnt = 0;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> p[i];
        if(p[i] == i) cnt ++ ;
    }
    cout << (cnt + 1 >> 1) << "\n";
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