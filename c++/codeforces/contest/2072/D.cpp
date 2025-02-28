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
    ll ans = 0, l = 1, r = 1;
    for(ll i = 1; i <= n; i ++ ) {
        ll cnt = 0, r1, maxx = 0;
        for(ll j = i + 1; j <= n; j ++ ) {
            if(a[j] < a[i]) {
                cnt ++ ;
                if(cnt > maxx) {
                    maxx = cnt;
                    r1 = j;
                }
            } else if(a[j] > a[i]) {
                cnt -- ;
            }
        }
        if(ans < maxx) {
            ans = maxx;
            l = i;
            r = r1;
        }
    }
    cout << l << " " << r << "\n";
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