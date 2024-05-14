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
    string str; cin >> str;
    ll si = str.size();
    vector<ll> z(si + 1);
    ll l = 0, r = 0;
    for(ll i = 1; i < si; i ++ ) { // 右端点最靠右的匹配段，l记录起点，r记录终点
        if(i <= r && z[i - l] < r - i + 1) {
            z[i] = z[i - l];
        } else {
            z[i] = max((ll)0, r - i + 1);
            while(i + z[i] < si && str[z[i]] == str[i + z[i]]) ++ z[i];
        }
        if(i + z[i] - 1 > r) {
            l = i; r = i + z[i] - 1;
        } 
    }
    ll maxx1 = 0, ans = 0;
    for(ll i = 1; i < si; i ++ ) {
        if(i + z[i] < si) {
            maxx1 = max(maxx1, z[i]);
        }
    }
    ll maxx2 = 0;
    for(ll i = si - 1; i > 0; i -- ) {
        if(i + z[i] == si) {
            if(z[i] <= maxx1) ans = max(ans, z[i]);
            if(z[i] > maxx2) {
                if(maxx2 != 0) {
                    ans = max(ans, maxx2);
                }
                maxx2 = z[i];
            }
        }
    }
    if(ans != 0) {
        string str1 = str.substr(0, ans);
        cout << str1 << "\n";
    } else {
        cout << "Just a legend" << "\n";
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