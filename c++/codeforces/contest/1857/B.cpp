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
    string str;
    cin >> str;
    ll l = str.length();
    ll c = 0;
    ll res = l;
    for(ll i = l - 1; i >= 1; i -- ) {
        if(str[i] + c >= '5') {
            c = 1 ; res = i; 
        }
        else {str[i] += c; c = 0;}
    }
    if(str[0] + c>= '5') {
        cout << '1';
        res = 0;
    }
    else str[0] += c; 
    for(ll i = 0; i < res; i ++ ) cout << str[i];
    for(ll i = res; i < l; i ++ ) cout << "0";
    cout << "\n";
}


signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}