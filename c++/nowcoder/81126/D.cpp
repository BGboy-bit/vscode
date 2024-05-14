#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 1e5 + 10;
ll a[MAX];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    ll aa = 0, bb = 0, cc = 0;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i]; 
        aa += a[i]; bb -= 2 * i * a[i]; cc += i * i * a[i];
    }
    ll x1 = (-bb) / (2 * aa), x2 = (-bb + 2 * aa) / (2 * aa); 
    ll ans = min(aa * x1 * x1 + bb * x1 + cc, aa * x2 * x2 + bb * x1 + cc);
    cout << ans << "\n";
    return 0;
}