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

    ll root, cnt;

    ll dfs(ll k, ll num, vector<ll> &p, vector<ll> &t, vector<vector<pair<ll, ll>>> &ori, vector<ll> &tt) {
        if(p[k] == 0) {
            tt[k] += t[k] * num;
            return t[k] * num;
        }
        ll summ = 0;
        for(auto i : ori[k]) {
            ll x = dfs(i.second, i.first, p, t, ori, tt);
            if(x == 0 || x > 1000000000) {
                if(k == root) cnt ++ ;
                else return 0;
                x = 0;
            }
            summ += x;
        }
        tt[k] += num * summ;
        return summ * num;
    }

    void Solve() {
        cnt = 0;
        ll n, k; cin >> n >> k;
        root = k;
        vector<ll> p(n + 1), t(n + 1);
        vector<vector<pair<ll, ll>>> ori(n + 1);
        for(ll i = 1; i <= n; i ++ ) {
            cin >> p[i];
            if(p[i] == 0) cin >> t[i];
            else {
                ll x; cin >> x;
                for(ll j = 1; j <= x; j ++ ) {
                    ll u, v; cin >> u >> v;
                    ori[i].push_back({u, v});
                }
            }
        }
        vector<ll> tt(n + 1);
        ll ans = dfs(k, 1, p, t, ori, tt);
        if(cnt >= 2) cout << "Impossible\n";
        if(cnt == 0) {
            ll maxx = 0;
            for(ll i = 1; i <= n; i ++ ) {
                if(i == k) continue;
                maxx = max(maxx, tt[i]);
            }
            ans -= maxx;
        } 
        if(ans > 1000000000) cout << "Impossible\n";
        else cout << ans << "\n";
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