    #include<bits/stdc++.h>
    using namespace std;
    typedef __int128 i128;
    typedef long long ll;
    typedef double db;

    const ll inf = 2e18 + 10;
    const int mod = 998244353;
    const int MAX = 2e5 + 10;
    bool multi = 1;//¶à×éÊäÈë

    ll n, m;
    ll fa[MAX];
    ll a[MAX];

    ll find(ll x) {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }

    void Solve() {
        cin >> n >> m;
        for(ll i = 1; i <= n; i ++ ) fa[i] = i;
        for(ll i = 1; i <= m; i ++ ) {
            ll x, y;
            cin >> x >> y;
            ll fx = find(x), fy = find(y);
            fa[fx] = fy;
        }
        ll k;
        cin >> k;
        for(ll i = 1; i <= k; i ++ ) {
            cin >> a[i];
        }
        for(ll i = 2; i <= k; i ++ ) {
            if(find(a[1]) != find(a[i])) {cout << "NO" << "\n"; return;}
        }
        cout << "YES" << "\n";
    }


    signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);
        ll T = 1;
        if(multi) cin >> T;
        while(T --) {
            Solve();
        }
        return 0;
    }