#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 1;//¶à×éÊäÈë

void Solve() {
    ll n;
    cin >> n;
    //8 5 2 7 3 1 6 3
    for(ll i = n; i > 7; i -= 8) {
        cout << i << " " << i - 3 << " " << i - 6 << " " << i - 1 << " " << i - 4 << " " << i - 7 << " " << i - 2 << " " << i - 5 << " ";
    }
    ll x = n % 8;
    if(x == 1) cout << "1" << "\n";
    else if(x == 2) cout << "2 1" << "\n";
    else if(x == 3) cout << "1 2 3" << "\n";
    else if(x == 4) cout << "4 3 2 1" << "\n";
    else if(x == 5) cout << "5 2 1 4 3" << "\n";
    else if(x == 6) cout << "4 1 2 3 6 5" << "\n";
    else if(x == 7) cout << "7 6 5 2 3 4 1" << "\n";
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}