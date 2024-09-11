#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long   ll;
typedef double db;

const int mod = 998244353;
const int MAX = 1e5 + 10;
bool multi = 1;//¶à×éÊäÈë


bool check(ll x) {
    ll t = sqrt(x);
    if(t * t == x) return true;
    return false;
}

void Solve() {
    ll n, m;
    cin >> n >> m;
    ll x = abs(n - m);
    ll ans = 0;
    
    if(x % 2 != 0) {
        if(check(x)) ans = 1; 
        else ans = 2;
    }
    else {
        if(check(x)) ans = 1;
        else {
            if(x % 4 == 0) ans = 2;
            else if(check(x - 1) || check(x + 1)) ans = 2;
            else {
                ans = 3;
                for(ll i = 1; i * i <= x; i ++ ) {
                    if(check(x - i * i)) {ans = 2; break;}
                }
            }
            
        }
    }
    cout << ans  << "\n";
    
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