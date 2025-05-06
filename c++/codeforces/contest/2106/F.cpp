    #include<bits/stdc++.h>
    using namespace std;
    typedef long long ll;

    void Solve() {
        ll n; cin >> n;
        string s; cin >> s; s = '1' + s;
        ll ans = 0, down = 0, up = 0;
        for(ll i = 1; i <= n; i ++ ) {
            if(s[i] == '0') {
                down += n - i;
                up += i - 1;
            } else {
                ans = max(ans, up); 
                up = down + 1; down = 0;
            }
        }
        ans = max(ans, max(down, up));
        cout << ans << "\n";
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