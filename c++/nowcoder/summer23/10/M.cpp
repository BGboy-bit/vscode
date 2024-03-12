#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 0;//∂‡◊È ‰»Î

string a = "12", b = "2", c = "14";

bool check() {
    ll l1 = a.length(), l2 = b.length(), l4 = c.length();
    vector<ll> v1, v2, v3, v4;
    ll t = 0;
    for(ll i = l1 - 1;i >= 0;i--) v1.push_back(a[i] - '0');
    for(ll i = l2 - 1;i >= 0;i--) v2.push_back(b[i] - '0');
    for(ll i = 0; i < l1 || i < l2; i ++ ) {
        if(i < l1) t += v1[i];
        if(i < l2) t += v2[i];
        v3.push_back(t % 10);
        t /= 10;
    }
    if(t > 0) v3.push_back(1);
    for(ll i = 0; i < l4; i ++ ) v4.push_back(c[i] - '0');
    for(ll i = v3.size() - 1; i >= 0; i -- ) {
        if(v3[i] != v4[l4 - i - 1]) return false;
    }
    return true;
}


void Solve() {
    if(check()) cout << "ok" << "\n";
    else cout << "wa" << "\n";
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