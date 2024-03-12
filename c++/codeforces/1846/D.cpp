#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int MAX = 2e5 + 10;
db y[MAX];
db xy[MAX];

void Solve() {
    db n, d, h;
    cin >> n >> d >> h;
    db s = d * h / 2; 
    for(ll i = 1; i <= n; i ++ ) {
        cin >> y[i];
        xy[i - 1] = y[i] - y[i - 1];
    } 
    db ans = s;
    for(ll i = 1; i < n; i ++ ) {
        if(xy[i] >= h) ans += s;
        else {
            ans += s - (h - xy[i]) * (h - xy[i]) * d / h / 2;
        }
    }
    cout << fixed << setprecision(6) << ans << "\n";  
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