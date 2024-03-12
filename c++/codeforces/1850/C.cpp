#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI=acos(-1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 1;//∂‡◊È ‰»Î

void Solve() {
    string str[9];
    for(ll i = 1; i <= 8; i ++ ) {
        cin >> str[i];
        for(auto j : str[i]) {
            if(j <= 'z' && j >= 'a') cout << j;
        }
    }
    cout << "\n";
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}