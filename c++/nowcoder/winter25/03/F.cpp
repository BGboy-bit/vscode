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
    ll a, b, c; cin >> a >> b >> c;
    ll ab, bc, ac, a1, b1, c1;
    // ac + ab + a1 = a; 
    // ac + bc + c1 = c;
    // ab + bc + b1 = b;
    // a1 + b1 + c1 + ac + bc + ab = n;
    if(a + b + c - 2 * n <= 0 && a + b + c - n >= 0) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
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