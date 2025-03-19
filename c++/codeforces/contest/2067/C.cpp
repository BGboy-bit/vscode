#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
typedef array<ll, 2> PII; // vector<PII> a(n + 1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int maxn = 2e5 + 10;
bool multi = 1;

ll nin[] = {0, 9, 99, 999, 9999, 99999, 999999, 9999999, 99999999, 999999999}; 

bool ins(ll x) {
    while(x > 0) {
        if(x % 10 == 7) {
            return true;
        } else {
            x /= 10;
        }
    }
    return false;
}

void Solve() {
    ll n; cin >> n;
    ll ans = 8;
    for(ll i = 1; i <= 9; i ++ ) {
        ll cnt = 0, x = n;
        while(!ins(x) && cnt <= 7) {
            x += nin[i]; cnt ++ ;
        } 
        if(ins(x)) {
            ans = min(ans, cnt);
        }
    }
    cout << ans << "\n";
}


signed main() {
    // freopen("test.in","r",stdin);  
    // freopen("code.out","w",stdout);    
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}