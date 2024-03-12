#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;



void Solve() {
    ll a, b;
    cin >> a >> b;
    if(a != 1 && b != 1) cout << "1" << "\n";
    else if(a == 2 || b == 2) {
        cout << "3" << "\n";
    }
    else cout << "2" << "\n";
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