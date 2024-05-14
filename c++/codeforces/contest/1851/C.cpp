#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;

ll n, k;
ll a[MAX];

void Solve() {
    cin >> n >> k;
    ll x, y;
    ll cnt1 = 0, cnt2 = 0;
    ll b = 0, c = 0;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
        if(i == 1) x = a[i];
        if(a[i] == x) cnt1 ++ ;
        if(cnt1 == k && b == 0) b = i;
    }
    y = a[n];
    for(ll i = n; i >= 1; i -- ) {
        if(a[i] == y) cnt2 ++ ;
        if(cnt2 == k && c == 0) {
            c = i;
            break;
        }
    }
    if(c >= b && c != 0 && b != 0) cout << "Yes" << "\n";
    else if(x == y && c != 0 && b != 0) cout << "Yes" << "\n";
    else cout << "No" << "\n";
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