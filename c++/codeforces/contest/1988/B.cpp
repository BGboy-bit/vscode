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
    ll n; cin >> n;
    string s; cin >> s;
    string a;
    for(ll i = 0; i < n; i ++ ) {
        if(s[i] == '1') a += '1';
        else {
            if(a.empty() || a.back() == '1') a += '0';
        } 
    }
    ll cnt = 0;
    for(ll i = 0; i < a.size(); i ++ ) {
        if(a[i] == '1') cnt ++ ;
        else cnt -- ; 
    }
    if(cnt <= 0) cout << "No" << "\n";
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