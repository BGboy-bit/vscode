    #include<bits/stdc++.h>
    using namespace std;
    typedef long long ll;

    ll tmp[505];

    void Solve() {
        ll n, m; cin >> n >> m;
        vector<ll> a(n + 1);
        set<ll> ans;
        for(ll i = 1; i <= n; i ++ ) {
            cin >> a[i];
            ll x = a[i];
            while(x) {
                ans.insert(x);
                x /= 2;
            }
        }
        ll res = 1e18;
        for(auto x : ans) {
            // vector<ll> tmp;
            for(ll i = 1; i <= n; i ++ ) {
                if(a[i] <= x) {
                    // tmp.push_back(x - a[i]); continue;
                    tmp[i] = x - a[i]; continue;
                }
                ll y = a[i], sum = 0;
                while(1) {
                    if(y / 2 <= x) {
                        sum += min(x - y / 2 + 1, y - x);
                        // tmp.push_back(sum);
                        tmp[i] = sum;
                        break;
                    }   
                    sum ++ ;
                    y /= 2;
                }
            }
            // sort(tmp.begin(), tmp.end());
            nth_element(tmp + 1, tmp + n - m + 1, tmp + n + 1);
            // sort(tmp + 1, tmp + n + 1);
            // for(ll i = 1; i <= n; i ++ ) {
            //     cout << tmp[i] << " \n"[i == n];
            // }    
            ll sum = 0;
            for(ll i = 1; i <= n - m; i ++ ) {
                sum += tmp[i];
            }
            res = min(sum, res);
        }
        cout << res << "\n";
    }

    int main() {
        ios::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);
        ll T; cin >> T;
        while(T -- ) {
            Solve();
        }
        return 0;
    }