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
    ll len; string s;
    cin >> len; cin >> s;
    ll l = 0, r = len - 1, res = 0;
    while(r - l + 1 >= 3) {
        if(s[l] != s[r]) {
            if(s[l] == '0' + res) l ++ ; 
            else r -- ;
            res = !res;
        }
        else if(s[l] == s[r] ) {
            if(s[l] != '0' + res) {cout << !res << "\n"; return ;}
            if(s[l + 1] == s[l] || s[r] == s[r - 1]) {cout << res << "\n"; return ;}
            if(s[l + 1] != s[l + 2]) {l ++ ; res = !res;}
            else if(s[r - 1] != s[r - 2]) {r -- ; res = !res;} 
            else {l ++ ; res = !res;}
        }
    }
    while(l <= r) {
        if(s[l] == '0' + res) {l ++ ; res = !res;}
        else if(s[r] == '0' + res) {r -- ; res = !res;}
        else {cout << !res << "\n"; return ;}
    }
    cout << "-1" << "\n";
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