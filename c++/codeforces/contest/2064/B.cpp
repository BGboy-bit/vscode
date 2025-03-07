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
    vector<ll> a(n + 1), b(n + 1);
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i]; b[a[i]] ++ ;
    }
    ll ans = 0, cnt = 0, l = 0, r = 0, l1;
    for(ll i = 1; i <= n; i ++ ) {
        if(b[a[i]] == 1) {
            cnt ++ ;
            if(cnt == 1) l1 = i;
        } else {
            if(ans < cnt) {
                l = l1, r = i - 1; ans = cnt;
            } 
            cnt = 0;
        }
    }
    if(ans < cnt) {
        l = l1, r = n; ans = cnt;
    } 
    if(l == 0) {
        cout << "0\n"; return ;
    } else {
        cout << l << " " << r << "\n"; return ;
    }
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