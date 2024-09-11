    #include<bits/stdc++.h>
    using namespace std;
    typedef __int128 i128;
    typedef long long ll;
    typedef double db;

    const ll inf = 2e18 + 10;
    const int mod = 998244353;
    const int MAX = 2e5 + 10;
    bool multi = 1;//¶à×éÊäÈë

    ll x, a, b;

    void Solve() {
        cin >> x >> a >> b;
        ll cnt = 0;
        ll ff; 
        bool f2 = 1, f3 = 1;    
        while(x != 0) {
            ll x1 = x - 1;
            ll x2 = (x + a) / 2;
            ll x3 = (ll)sqrt(x + b);
            if(x1 <= x2) f2 = 0;
            if(x1 <= x3) f3 = 0;
            if(!f2 && !f3) break;
            else if(!f2) x = x3;
            else if(!f3)x = x2;
            else x = min(x2, x3);  
            cnt ++ ;
        }
        cnt += x;
        cout << cnt << "\n";
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