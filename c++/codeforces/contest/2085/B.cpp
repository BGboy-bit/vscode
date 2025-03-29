    #include<bits/stdc++.h>
    using namespace std;
    typedef long long ll;

    void Solve() {
        ll n; cin >> n;
        vector<ll> a(n + 1);
        bool ff = 0;
        for(ll i = 1; i <= n; i ++ ) {
            cin >> a[i];
            if(a[i] == 0 && i < n - 1) {
                ff = 1;
            }
        }
        if(a[n] != 0) {
            if(!ff && a[n - 1] > 0) {
                cout << "1\n";
                cout << "1 " << n << "\n";
            } else {
                cout << "2\n";
                cout << "1 " << n - 1 << "\n";
                cout << "1 2\n"; 
            }
        } else {
            if(!ff) {
                cout << "2\n";
                cout << n - 1 << " " << n << "\n";
                cout << "1 " << n - 1 << "\n";
            } else {
                cout << "3\n";
                cout << "1 " << n - 2 << "\n";
                cout << "2 3\n"; 
                cout << "1 2\n";
            }
        }
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