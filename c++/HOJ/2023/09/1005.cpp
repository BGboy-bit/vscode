#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 5e5 + 10;
bool multi = 1;//¶à×éÊäÈë

void Solve() {
    string s, str;
    getline(cin, s);
    // getchar();
    getline(cin, str);
    ll x, y;
    cin >> x >> y;
    ll m = 0;
    vector<ll> v;
    for(ll i = 1; i < str.length(); i ++ ) {
        if(str[i] <= '9' && str[i] >= '0') m = m * 10 + (str[i] - '0');
        else if(str[i - 1] <= '9' && str[i - 1] >= '0') {
            v.push_back(m); m = 0;
        }
    }
    ll cnt = 0;
    cout << "[";
    for(ll j = 1; j <= x; j ++ ) {
        cout << "[";
        for(ll i = 1; i <= y; i ++ ) {
            cout << v[cnt ++ ];
            if(i != y) cout << ", ";
        }
        cout << "]";
        if(j != x) cout << ", ";
        else cout << ']';
    }
    cout << "\n";
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    string str;
    if(multi) cin >> T;
    
    while(T --) {
        Solve();
    }
    return 0;
}