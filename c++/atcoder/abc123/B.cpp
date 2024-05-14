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

map<char, ll> mp1;
map<ll, ll> mp2;

void Solve() {
    ll maxx = 0;
    string str; cin >> str;
    for(ll i = 1; i <= str.length(); i ++ ) {
        mp1[str[i - 1]] ++ ;
        maxx = max(maxx, mp1[str[i - 1]]);
    }
    for(char i = 'a'; i <= 'z'; i ++ ) {
        mp2[mp1[i]] ++ ;
    }
    for(ll i = 1; i <= maxx; i ++ ) {
        if(mp2[i] != 2 && mp2[i] != 0) {
            cout << "No" << "\n";
            return ;
        }
    }
    cout << "Yes" << "\n";
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