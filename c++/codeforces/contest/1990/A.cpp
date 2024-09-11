#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
typedef array<ll, 2> PII; // vector<PII> a(n+1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 1;

void Solve() {
    ll n; cin >> n;
    vector<ll> a(n + 1);
    for (ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    ll maxx = inf, cnt = -1;
    for(ll i = n; i >= 1; i -- ) {
        if(maxx > a[i]) {
            if(cnt != -1) {
                if(cnt % 2 == 1) {
                    cout << "Yes" << "\n";
                    return ;
                }
            }
            maxx = a[i];
            cnt = 1;
        } else {
            cnt ++ ;
        }
    }
    if(cnt % 2 == 1) cout << "Yes" << "\n";
    else cout << "No" << "\n";
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}