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
    string a, b; cin >> a >> b;
    a = '!' + a; b = '!' + b;
    string a1 = a, b1 = b;
    for(ll i = 1; i <= n - 2; i ++ ) {
        if(a[i] == '0' && a[i + 2] == '0') b1[i + 1] = '1';
    }
    for(ll i = 1; i <= n - 2; i ++ ) {
        if(b1[i] == '1' && b1[i + 2] == '1') a1[i + 1] = '1';
    }
    vector<ll> summ(n + 1);
    summ[0] = 0;
    for(ll i = 1; i <= n; i ++ ) {
        if(a1[i] == '1') summ[i] = summ[i - 1] + 1;
        else summ[i] = summ[i - 1];
    }
    ll q; cin >> q;
    while(q -- ) {
        ll l, r; cin >> l >> r;
        ll ans = 0;
        // bool ff = 0;
        // if(r - l >= 2 && b[l] == '0' && b1[l] == '1' && b[l + 2] == '1' && a[l + 1] == '0') {
        //     ans -= 1;
        //     ff = 1;
        // }
        // if((r - l > 2 || r - l == 2 && ff == 0) && b[r] == '0' && b1[r] == '1' && b[r - 2] == '1' && a[r - 1] == '0') ans -= 1;  
        
        // if(l >= 2 && l <= n && b1[l - 1] == '1' && b1[l + 1] == '1' && a[l] == '0') ans -= 1;
        // if(l != r && r <= n - 1 && r >= 2 && b1[r + 1] == '1' && b[r - 1] == '1' && a[r] == '0') ans -= 1;
        if(r - l <= 4) {
            string aa(a, l - 1, r - l + 2), bb(b, l - 1, r - l + 2);
            for(ll i = 1; i <= r - l - 1; i ++ ) {
                if(aa[i] == '0' && aa[i + 2] == '0') bb[i + 1] = '1';
            }
            for(ll i = 1; i <= r - l - 1; i ++ ) {
                if(bb[i] == '1' && bb[i + 2] == '1') aa[i + 1] = '1';
            }
            for(ll i = 1; i <= r - l + 1; i ++ ) {
                ans += ll(aa[i] - '0');
            }
        } else {
            ans = summ[r - 2] - summ[l + 1] + ll(a[r] - '0') + ll(a[l] - '0');
            if(b[l] == '1' && b1[l + 2] == '1') ans += 1;
            else ans += ll(a[l + 1] - '0');
            if(b[r] == '1' && b1[r - 2] == '1') ans += 1;
            else ans += ll(a[r - 1] - '0');
        }
        cout << ans <<"\n";
    }
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