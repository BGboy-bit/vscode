#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

ll n, x;

void Solve() {
    cin >> n >> x;
    if(n % x != 0) cout << "1" << "\n" << n << "\n";
    else cout << "2" << "\n" <<  n + 1 << " " << "-1" << "\n";
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