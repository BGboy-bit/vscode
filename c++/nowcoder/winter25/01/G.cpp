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
bool multi = 0;

void Solve() {
    ll n; cin >> n;
    vector<ll> a(n + 1);
    ll summ = 0;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
        summ += a[i];
    }
    sort(a.begin() + 1, a.end());
    if(summ != n * (n + 1) / 2) {
        cout << "-1\n"; return ;
    }
    ll cnt1 = 0, cnt2 = 0, ans = 0;
    for(ll i = n; i >= 1; i -- ) {
        if(a[i] != i) {
            if(a[i] > i) {
                if(cnt2 < a[i] - i) {
                    cnt1 += a[i] - i - cnt2; 
                    ans += a[i] - i - cnt2;
                    cnt2 = 0;
                } else {
                    cnt2 -= a[i] - i;
                }
            } else {
                if(cnt1 < i - a[i]) {
                    cnt2 += i - a[i] - cnt1; 
                    ans += i - a[i] - cnt1;
                    cnt1 = 0;
                } else {
                    cnt1 -= a[i] - i;
                }
            }
        }
    }
    cout << ans << "\n";
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