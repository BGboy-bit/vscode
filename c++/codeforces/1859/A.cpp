#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 1;//¶à×éÊäÈë

ll n;
ll a[MAX];


void Solve() {
    cin >> n;
    vector<ll> b, c;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    c.push_back(a[n]);
    for(ll i = n - 1; i >= 1; i -- ) {
        if(a[i] == a[n]) c.push_back(a[i]);
        else b.push_back(a[i]);
    }
    if(b.size() == 0) cout << "-1" << "\n";
    else {
        cout << b.size() << " " << c.size() << "\n";
        for(auto i : b) cout << i << " ";
        cout << "\n";
        for(auto i : c) cout << i << " ";
        cout << "\n";
    }
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