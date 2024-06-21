#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n, m; cin >> n >> m;
    string s;
    ll x = 0, y = 0, cnt = 0;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> s; s = '!' + s;
        for(ll j = 1; j <= m; j ++ ) {
            if(s[j] == '#') {
                x += i; y += j, cnt ++ ;
            }
        }
    }
    cout << x / cnt << " " << y / cnt << "\n";
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