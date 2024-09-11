#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
typedef array<ll, 2> PII; // vector<PII> a(n+1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 1;

void Solve() {
    string s; cin >> s;
    ll cnt1 = 0, cnt2 = 0;
    for(ll i = 0; i <= 7; i ++ ) {
        if(s[i] == s[0]) cnt1 ++ ;
        else if(s[i] == s[4]) cnt2 ++ ;
    }
    if(s[0] == s[4]) {
        cout << s[0] << "\n";
    } else if(cnt1 != cnt2) {
        if(cnt1 > cnt2) cout << s[0] << "\n";
        else cout << s[4] << "\n";
    } else {
        cout << "N" << "\n";
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