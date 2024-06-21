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
    bool ff = 0;
    for(ll i = 0; i < s.size(); i ++ ) {
        if(i == 0 && s[i] != '1' || i != s.size() - 1 && s[i] == '0' || i == s.size() - 1 && s[i] == '9') {
            ff = 1; break;
        }   
    }
    if(ff) cout << "No" << "\n";
    else cout << "Yes" << "\n";
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