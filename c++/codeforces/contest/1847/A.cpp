#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int MAX = 1000;
ll n, k;
ll a[MAX], b[MAX];

void Solve() {
    cin >> n >> k;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
        if(i > 1) b[i - 1] = abs(a[i] - a[i - 1]);
    }
    sort(b + 1, b + n);
    ll ans = 0;
    for(ll i = 1; i <= n - k; i ++ ) ans += b[i];
    cout << ans << "\n";
    
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