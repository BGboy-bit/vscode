#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 1;//¶à×éÊäÈë

ll p2[42];
ll n;

void Solve() {
    cin >> n;
    vector<ll> a(p2[n]);
    vector<ll> v;
    unordered_map<ll, ll> mp;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
        if(mp[a[i]] == 0 && a[i] != 0) v.push_back(a[i]);
        mp[a[i]] ++ ;
    }
    sort(v.begin(), v.end());
    ll pos = inf;
    for(ll i = 0; i <= 40; i ++ ) {
        if(p2[i] - 1 == v.size()) {
            pos = i; break;
        }
    }
    if(pos == inf) {cout << "-1" << "\n"; return ;}
    for(ll i = 0; i <= 40; i ++ ) {
        if(p2[i] - 1 == v.back()) {
            for(auto j : v) {
                if(mp[j] != p2[n - pos]) {cout << "-1" << "\n"; return ;}
            }
            for(ll i = 1; i <= n - pos; i ++ ) cout << "0" << " ";
            
        } 
    }
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    p2[0] = 1;
    for(ll i = 1; i <= 42; i ++ ) p2[i] = p2[i - 1] * 2;
    ll T = 1;
    if(multi) cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}