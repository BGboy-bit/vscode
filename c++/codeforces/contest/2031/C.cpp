
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

void Solve() {
    ll n; cin >> n;
    if(n % 2 == 0) {
        for(ll i = 1; i <= n; i ++ ) {
            cout << (i + 1) / 2 << " \n"[i == n]; 
        }
    } else {
        if(n < 27) {
            cout << "-1\n"; return ;
        }
        cout << "1 ";
        for(ll i = 2; i <= 9; i ++ ) {
            cout << (i + 2) / 2 << " ";
        }
        cout << "1 ";
        for(ll i = 11; i <= 22; i ++ ) {
            cout << (i + 1) / 2 << " ";
        }
        cout << "12 13 13 1 12 ";
        for(ll i = 28; i <= n; i ++ ) {
            cout << i / 2 << " \n"[i == n];
        }
    }
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