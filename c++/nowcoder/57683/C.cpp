#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int MAX = 1e3 + 10;
ll n, m; 
ll a[MAX], b[MAX];

void insert(ll l, ll r,ll x) {
    b[l] += x;
    b[r + 1] -= x; 
} 

void Solve() {
    bool f = 0;
    cin >> n;
    for(ll i = 1; i <= n; i ++ ) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(ll i = 1; i <= n; i ++ ) {
        insert(i, i, a[i]);
    }
    for(ll i = 1; i <= n; i ++ ) if(b[i] < 1) f = 1;
    if(f) cout << "-1" << "\n";
    else {
        for(ll i = 1; i <= n; i ++ ) cout << a[i] << " ";
        cout << "\n";
    }
    for(ll i = 1; i <= n + 1; i ++ ) b[i] = 0;
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