    #include<bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    typedef double db;

    const int MAX = 2e5 + 10;
    ll n, k;
    ll a[MAX], b2[MAX], b5[MAX];
    ll p2[MAX], p5[MAX];

    void Solve() {
        bool f = 0;
        cin >> n >> k;
        for(ll i = 1; i <= n + 5; i ++ ) b2[i] = b5[i] = 0;
        ll ans = 0;
        for(ll i = 1; i <= n; i ++ ) {
            cin >> a[i]; 
            while(a[i] % 2 == 0) {
                a[i] /= 2;
                b2[i] ++;
            }
            while(a[i] % 5 == 0) {
                a[i] /= 5;
                b5[i] ++;
            }
            p2[i] = p2[i - 1] + b2[i];
            p5[i] = p5[i - 1] + b5[i];
        } 
        for(ll i = 1; i <= n; i ++ ) {
            ll l2 = lower_bound(p2, p2 + n + 1, k + p2[i - 1]) - p2;
            ll r2 = upper_bound(p2, p2 + n + 1, k + p2[i - 1]) - p2;
            ll l5 = lower_bound(p5, p5 + n + 1, k + p5[i - 1]) - p5;
            ll r5 = upper_bound(p5, p5 + n + 1, k + p5[i - 1]) - p5;
            ll l = max(l2, l5);
            ll r = max(r2, r5);
            l = max(l, i);
            if(l == n + 1) continue;
            ans += r - l;
        }

        cout << ans << "\n";
    }


    int main() {
        ios::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);
        ll T = 1;
        cin >> T;
        while(T --) {
            Solve();
        }
        return 0;
    }