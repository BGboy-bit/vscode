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
bool multi = 0;

void Solve() {
    string s, t; cin >> s >> t;
    ll cnt = 0;
    for(ll i = 0; i < s.length(); i ++ ) {
        if(s[i] - 'a' + 'A' == t[cnt]) cnt ++ ;
    }
    if(cnt == t.length()) {
        cout << "Yes" << "\n";
    } else {
        if(cnt == 2 && t[cnt] == 'X') cout << "Yes" << "\n";
        else cout << "No" << endl;
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