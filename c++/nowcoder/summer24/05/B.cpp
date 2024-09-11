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
    ll n, m, a, b; cin >> n >> m >> a >> b;
    if(n == 1 && m == 2 || n == 2 && m == 1) {
        cout << "Yes\n"; return ;
    }
    if(a == 0 && b == 0) {
        cout << "No\n"; return ;
    } 
    if(a == 1 && b == 0) {
        if(n == 1 && m % 2 == 0 || n % 2 == 0 && m == 1) cout << "Yes\n";
        else cout << "No\n";
        return ;
    }
    if(a == 0 && b == 1) {
        if(n == 2 || m == 2) cout << "Yes\n";
        else cout << "No\n";
        return ;
    }
    if(a == 1 && b == 1) {
        if(n % 2 == 0 || m % 2 == 0) cout << "Yes\n";
        else cout << "No\n";
        return ;
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