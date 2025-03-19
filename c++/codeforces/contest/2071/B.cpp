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

    bool isper(ll x) {
        if(x == 1) {
            return true;
        }
        ll l = 2, r = x; 
        while(l <= r) {
            ll mid = l + r >> 1;
            if(x / mid == mid && x % mid == 0) {
                return true;
            } else {
                if(mid > x / mid) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }
        return false;
    }

    void Solve() {
        ll n; cin >> n;
        if(n == 1) {
            cout << "-1\n"; return ;
        }
        ll cnt = 0;
        vector<ll> a(n + 1);
        iota(a.begin() + 1, a.end(), 1);
        for(ll i = 1; i <= n; i ++ ) {
            cnt += i;
            if(isper(cnt)) {
                if(i == n) {
                    cout << "-1\n"; return ;
                }
                else swap(a[i + 1], a[i]);
                cnt += i + 1; i ++ ;
            }
        }
        for(ll i = 1; i <= n; i ++ ) {
            cout << a[i] << " \n"[i == n];
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