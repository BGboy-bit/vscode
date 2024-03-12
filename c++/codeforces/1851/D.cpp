#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;

ll n;
ll b[MAX], c[MAX];

void Solve() {
    cin >> n;
    vector<bool> ff(n * 2 + 10, 0);
    ll x = 0;
    bool f = 1;
    for(ll i = 1; i < n; i ++ ) {
        cin >> b[i];
        c[i] = b[i] - b[i - 1];
        if(c[i] >= 2 * n) f = 0;
        else {
            if(ff[c[i]] == 0 && c[i] <= n) ff[c[i]] = 1;
            else {
                if(x == 0) x = c[i];
                else f = 0;
            }
        } 
    }
    if(b[n - 1] > n * (n + 1) / 2 || f == 0) cout << "No" << "\n";
    else {
        ll y = 0, z = 0;
        for(ll i = 1; i <= n; i ++ ) {
            if(!ff[i]) {
                if(y == 0) y = i;
                else z = i;
            }
        }
        if(x == 0 && z == 0 && y != 0) cout << "Yes" << "\n";
        else if(x == z + y) cout << "Yes" << "\n";
        else cout << "No" << "\n";
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