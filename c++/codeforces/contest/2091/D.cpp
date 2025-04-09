    #include<bits/stdc++.h>
    using namespace std;
    typedef long long ll;

    ll n, m, k, x; 
    bool check(ll mid) {
        ll y = (x - 1) / mid * (mid + 1) + x % mid;
        if(x % mid == 0) y += mid;
        if(y <= m) {
            return true;
        } else {
            return false;
        }
    }

    void Solve() {
        cin >> n >> m >> k;
        x = (k + n - 1) / n;
        ll l = 1, r = x;
        while(l < r) {
            ll mid = l + r >> 1;
            if(check(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        cout << l << "\n";
    }

    int main() {
        ios::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);
        ll T = 1; cin >> T;
        while(T -- ) {
            Solve();
        }
        return 0;
    }