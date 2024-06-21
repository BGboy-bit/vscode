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
    vector<ll> a(n + 1);
    map<ll, ll> mp, mp1;
    ll cnt1 = 0, cnt2 = 0;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
        mp[a[i]] ++ ;
        if(mp[a[i]] == 2) {
            cnt2 ++ ;
        } 
        if(mp[a[i]] == 1) {
            cnt1 ++ ;
        }
    }
    if(cnt2 > 0 && cnt1 >= 2 || cnt1 >= 3) {
        cout << "YES\n";
        bool ff = 0;
        for(ll i = 1; i <= n; i ++ ) {
            if(mp[a[i]] == 1 && cnt2 > 0 || ff == 1) cout << "B";
            else {
                cout << "R";
                ff = 1;
            }
        }
        cout << "\n";
    } else {
        cout << "NO\n";
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