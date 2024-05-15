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
    string s; cin >> s;
    ll si = s.size();
    vector<ll> z(si), cnt(si + 1);
    for(ll i = 1, l = 0, r = 0; i < si; i ++ ) {
        if(i <= r && z[i - l] < r - l + 1) {
            z[i] = z[i - l];
        } else {
            z[i] = max((ll)0, r - i + 1);
            while(i + z[i] < si && s[z[i]] == s[i + z[i]]) ++ z[i];
        }
        cnt[z[i]] ++ ;
    }
    
    ll cntt = 0, cntt1 = 1;
    for(ll i = si - 1; i >= 1; i -- ) {
        cntt += cnt[i + 1];
        if(cnt[i] != 0) {
            cntt1 ++ ;
            cnt[i] += cntt;
        }  
    }
    cout << cntt1 << "\n";
    for(ll i = 1; i <= si; i ++ ) {
        if(cnt[i] != 0) {
            cout << i << " " << cnt[i] + 1 << "\n";
        } else if(i == si) {
            cout << i << " " << 1 << "\n";
        }
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