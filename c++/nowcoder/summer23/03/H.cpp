#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 1010;

ll n;
ll a[MAX];
ll sum;

bool Prime(ll x) {
    for(ll i = 2; i * i <= x; i ++ ) {
        if(x % i == 0) return 0;
    }
    return 1;
}

void Solve() {
    cin >> n;
    for(ll i = 1; i <= n ; i ++ ) {
        cin >> a[i];
        sum += a[i];
    }
    if(n == 2 && sum % 2 == 1 && !Prime(sum - 2)) cout << "No" << "\n";
    else if(n == 1 && !Prime(a[1])) cout << "No" << "\n"; 
    else if(sum - n * 2 < 0) cout << "No" << "\n";
    else cout << "Yes" << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    // cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}