#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 1e5 + 10;

ll n, q;
ll a[MAX], b[MAX], c[MAX];
void Solve() {
    cin >> n >> q;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
        b[i] = a[i] + b[i - 1];
        if(b[i] % 2 == 0) c[i] = c[i - 1] + 1;
        else c[i] = c[i - 1];
    }
    while(q -- ) {
        ll l, r, k;
        cin >> l >> r >> k;
        if(r - l < k - 1) {
            cout << "NO" << "\n"; continue ;
        }
        if((b[r] - b[l - 1]) % 2 != 0 && b[r] % 2 != 0) k ++ ;
        if(b[l - 1] % 2 == 0) {
           
            if(c[r] - c[l - 1] < k) cout << "NO" << "\n";
            else cout << "YES" << "\n";
        }
        else {
            if(r - l + 1 - (c[r] - c[l - 1]) < k) cout << "NO" << "\n";
            else cout << "YES" << "\n"; 
        }
        
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}