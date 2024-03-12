#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 3e5 + 10;
bool multi = 1;//¶à×éÊäÈë

ll a[MAX];

void Solve() {
    ll n;
    cin >> n;
    vector<bool> ff(n + 1, 0);
    ll minn = inf, nim = inf; ll cnt = 0;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
        if(a[i] < minn) {
            minn = a[i];
        }  
        else if(a[i] < nim) {
            cnt ++ ; nim = a[i];
        }   
    }
    cout << cnt << "\n";
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