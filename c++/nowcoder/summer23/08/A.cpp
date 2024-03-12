#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 0;//∂‡◊È ‰»Î

set<string> s;
map<string, ll> mp;
vector<string> v;

void Solve() {
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i ++ ) {
        ll m;
        cin >> m;
        for(ll j = 1; j <= m; j ++ ) {
            string str;
            cin >> str;
            s.insert(str);
            mp[str] ++ ;
        }
    }
    for(auto i : s) {
        if(mp[i] == n) v.push_back(i);
    }
    sort(v.begin(), v.end());
    cout << v.size() << "\n";
    for(auto i : v) cout << i << "\n";
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