#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 0;//∂‡◊È ‰»Î

string str[5];

void reserve() {
    string str1[5];
    for(ll i = 0; i < 5; i ++ ) str1[4 - i] = str[i];
    for(ll i = 0; i < 5; i ++ ) str[i] = str1[i];
}

void Solve() {
    string str[5];
    for(ll i = 0; i < 5; i ++ ) cin >> str[i];
    reserve();
    for(ll i = 0; i < 5; i ++ ) cout << str[i] << " ";
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