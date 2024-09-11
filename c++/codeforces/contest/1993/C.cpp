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
    ll n, k; cin >> n >> k;
    vector<ll> a(n + 1);
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    ll maxx = a[n];
    for(ll i = 1; i < n; i ++ ) {
        if(((maxx - a[i]) / k) % 2 == 1) 
        a[i] += ((maxx - a[i]) / k + 1) * k;
        else a[i] += (maxx - a[i]) / k * k;
    }
    sort(a.begin() + 1, a.end());
    ll cnt1 = a[1], cnt2 = a[n], res = n;
    while(cnt2 - cnt1 >= k && cnt2 != maxx) {
        cnt2 -= 2 * k;
        cnt1 = cnt2;
        cnt2 = a[ -- res];
    }
    if(cnt2 - cnt1 >= k) cout << "-1" << "\n";
    else cout << cnt2 << "\n";
}


signed main() {
    // freopen("test.in","r",stdin);  
    // freopen("code.out","w",stdout);    
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}