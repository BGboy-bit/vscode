#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n; cin >> n;
    vector<vector<ll>> a(4, vector<ll>(n + 1)), pre(4, vector<ll>(n + 1));
    for(ll i = 1; i <= 3; i ++ ) {
        pre[i][0] = 0;
        for(ll j = 1; j <= n; j ++ ) {
            cin >> a[i][j];
            pre[i][j] = a[i][j] + pre[i][j - 1];
        }
    }
    vector<ll> perm = {1, 2 ,3};
    for(ll i = 1; i <= n; i ++ ) {
        
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T; cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}