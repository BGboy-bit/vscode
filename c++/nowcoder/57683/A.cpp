#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

ll n, m;

void Solve() {
    cin >> n;
    if(n % 3 != 0) m = n + 3 - n % 3;
    else m = n;
    cout << m << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
//  cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}