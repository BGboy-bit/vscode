#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 1e5 + 10;
ll n, m, l, r;
ll a[MAX], b[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
        b[i] = b[i - 1] + a[i];
    }
    while(m -- ) {
        cin >> l >> r;
        cout << b[r] - b[l - 1] << "\n";
    }
    return 0;
}