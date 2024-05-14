#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n, cnt = 0;
    cin >> n;
    while(n % 3 == 0) {
        n = n / 3 * 2;
        cnt ++;
    }
    while(n % 5 == 0) {
        n = n / 5 * 4;
        cnt ++;
    }
    while(n % 2 == 0) {
        n /= 2;
        cnt ++;
    }
    if(n != 1) cout << "-1" << "\n";
    else cout << cnt << "\n";
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