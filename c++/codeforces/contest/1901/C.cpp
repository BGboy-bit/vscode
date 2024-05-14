#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 1;//¶à×éÊäÈë


void Solve() {
    ll n, a; cin >> n;
    ll maxx = 0, minn = inf;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a;
        maxx = max(maxx, a);
        minn = min(minn, a);
    }
    if(maxx - minn <= 1) {
        if(maxx - minn == 1) {
            cout << "1" << "\n";
            if(maxx % 2 == 0) cout << "1" << "\n";
            else cout << "0" << "\n";
        }
        else cout << "0" << "\n";
    }
    else {
        vector<ll> v;
        while(maxx - minn > 0) {
            if(minn % 2 == 1)  {
                maxx = (maxx + 1) / 2; minn = (minn + 1) / 2;
                v.push_back(1);
            }
            else {
                maxx = maxx / 2; minn = minn / 2;
                v.push_back(0);
            }
            
        }
        cout << v.size() + maxx - minn << "\n";
        if(v.size() + maxx - minn <= n) {
            for(auto i : v) cout << i << " ";
            cout << "\n";
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