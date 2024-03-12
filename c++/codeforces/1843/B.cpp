#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int MAX = 2e5 + 10;
ll n;
ll a[MAX];

void Solve() {
    cin >> n;
    ll sum = 0;
    ll ans = 0;
    bool f = 0;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
        ans += abs(a[i]);
    }
    for(ll i = 1; i <= n; i ++ ) {
        if(a[i] > 0 && f == 1) f = 0;
        else if(a[i] < 0 && f == 0) {
            sum ++ ;
            f = 1;
        }
    }
    cout << ans << " " << sum << "\n";
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