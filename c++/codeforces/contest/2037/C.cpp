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
    if(n <= 4) {
        cout << "-1\n"; return ;
    }
    for(ll i = 1; i <= n; i += 2) {
        if(i == 5) continue;
        cout << i << " ";
    }
    cout << "5 4 ";
    for(ll i = 2; i <= n; i += 2) {
        if(i == 4) continue;
        cout << i << " ";
    } 
    cout << "\n";
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