#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    ll ans = (n / 3 + 1) * (n / 3) + (n - 3 + n % 3) * (n / 3) / 2;
    cout << ans << "\n";
    return 0;
}