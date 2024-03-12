#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int inf = 0x3f3f3f3f;
const int MAX = 2e5 + 10;

void Solve() {
    ll n, m;
    cin >> n >> m;
    if(n == 1 && m == 1) cout << "Walk Alone" <<"\n";
    else cout << "Kelin" << "\n";

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