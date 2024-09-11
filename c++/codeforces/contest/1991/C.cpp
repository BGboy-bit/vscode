#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
typedef array<ll, 2> PII; // vector<PII> a(n + 1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int maxn = 2e5 + 10;
bool multi = 1;

void Solve() {
    ll n; cin >> n;
    vector<ll> a(n + 1);
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    ll cnt = 0, x;
    vector<ll> ans;
    while(a[1] != a[n]) {
        if(cnt == 39) {
            cout << "-1" << "\n";
            return ;
        } 
        cnt ++ ;
        x = a[n] + a[1] >> 1; ans.push_back(x);
        for(ll i = 1; i <= n; i ++ ) {
            a[i] = abs(a[i] - x);
        }
        sort(a.begin() + 1, a.end());
    }
    cnt ++ ; ans.push_back(a[1]);
    cout << cnt << "\n";
    cout << ans[0];
    for(ll i = 1; i < cnt; i ++ ) {
        cout << " " << ans[i];
    }
    cout << "\n";
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