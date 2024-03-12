#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 110;
ll n, a[MAX];

void Solve() {
    ll sum = 0;
    cin >> n;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
        sum += a[i];
    }
    cout << (sum + n - 1) / n << "\n"; 
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