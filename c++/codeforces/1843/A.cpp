#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int MAX = 110;
ll n;
ll a[MAX];

void Solve() {
    cin >> n;
    ll sum = 0;
    for(ll i = 1; i <= n; i ++ ) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(ll i = 1; i <= n / 2; i ++ ) {
        sum += a[n - i + 1] - a[i]; 
    }
    cout << sum << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}