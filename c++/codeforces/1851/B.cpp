#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;

ll n;
ll a[MAX], b[MAX], c[MAX];

void Solve() {
    cin >> n;
    ll cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
    vector<bool> ff(n + 1, 0);
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
        if(a[i] % 2 == 0) {
            b[++ cnt1] = a[i];
            ff[i] = 1;
        }
        else c[++ cnt2] = a[i];
    }
    sort(b + 1, b + cnt1 + 1);
    sort(c + 1, c + cnt2 + 1);
    ll maxx = -1;
    bool f = 0;
    for(ll i = 1; i <= n ; i ++ ) {
        if(ff[i]) a[i] = b[++ cnt3];
        else a[i] = c[++ cnt4];
        if(maxx > a[i]) {
            f = 1; break;
        }
        else maxx = a[i];
    }
    if(f) cout << "No" << "\n";
    else cout << "Yes" << "\n";
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