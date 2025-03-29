#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n; cin >> n;
    vector<vector<ll>> a(n + 1, vector<ll> (n + 1));
    for(ll i = 1; i <= n; i ++ ) {
        for(ll j = 1; j <= n; j ++ ) {
            cin >> a[i][j];
        }
    }
    vector<ll> b;
    for(ll i = 1; i <= n; i ++ ) {
        bool ff = 0;
        for(ll j = n; j >= 1; j -- ) {
            if(a[i][j] != 1) {
                b.push_back(n - j); 
                ff = 1; break;
            }
        }
        if(!ff) b.push_back(n);
    }
    sort(b.begin(), b.end());
    ll nw = 1; 
    for(ll i = 0; i < b.size(); i ++ ) {
        if(b[i] >= nw) {
            nw ++ ;
        }
    }
    if(nw == n + 1) nw -- ;
    cout << nw << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1; cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}