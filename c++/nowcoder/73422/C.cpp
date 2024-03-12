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

void Solve() {
    map<char, ll> mp; 
    string s; cin >> s;
    string t = "xiaohong";
    cout << t;
    for(auto i : t) mp[i] ++ ;
    for(auto i : s) {
        if(mp[i] > 0) mp[i] -- ;
        else cout << i;
    }
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