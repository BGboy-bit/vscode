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

ll n, k; 
string s;

bool check(ll x, vector<ll> &a) {
    char nw = 'R';
    ll cnt = 0;
    for(ll i = 0; i < n; i ++ ) {
        if(a[i] > x) {
            if(s[i] == 'B' && a[i] > x && nw == 'R') {
                cnt += 1;
            }
            nw = s[i];
        }
    }
    return cnt <= k;
}

void Solve() {
    cin >> n >> k;
    cin >> s;
    vector<ll> a(n + 1);
    for(ll i = 0; i < n; i ++ ) {
        cin >> a[i];
    }   
    ll l = 0, r = 1000000000;
    while(l < r) {
        ll mid = l + r >> 1;
        if(check(mid, a)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << "\n";
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