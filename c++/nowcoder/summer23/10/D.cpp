#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 0;//∂‡◊È ‰»Î


bool cmp(ll u, ll v) {
    return u < v;
}

void Solve() {
    ll n, m;
    cin >> n >> m;
    vector a(n + 1, std::vector<char> (m + 1));
    for(ll i = 1; i <= n; i ++ ) {
        for(ll j = 1; j <= m; j ++ ) {
            cin >> a[i][j]; 
        }
    }

    if(m % 2 == 0) {
        ll ans = 0;
        for(ll i = 1; i <= n; i ++ ) {
            ll cnt = 0;
            for(ll j = 1; j <= m / 2; j ++ ) {
                if(a[i][j] == '1') cnt ++ ;
            }
            ans += cnt - 1; cnt = 0;
            for(ll j = m / 2 + 1; j <= m; j ++ ) {
                if(a[i][j] == '1') cnt ++ ;
                
            }
            ans += cnt - 1;
        }
        if(ans % 2 == 0) cout << "Bob" << "\n";
        else cout << "Alice" << "\n";
    }

    else {
        vector<ll> v;
        ll ans = 0;
        for(ll i = 1; i <= n; i ++ ) {
            ll cnt1 = 0, cnt2 = 0;
            for(ll j = 1; j <= m / 2; j ++ ) {
                if(a[i][j] == '1') cnt1 ++ ;
            } 
            if(a[i][m / 2 + 1] == '1') ans += max(cnt1, (ll)0);
            else ans += max(cnt1 - 1, (ll)0);
            for(ll j = m / 2 + 2; j <= m; j ++ ) {
                if(a[i][j] == '1') cnt2 ++ ;
            }
            if(a[i][m / 2 + 1] == '1') ans += max(cnt2, (ll)0);
            else ans += max(cnt2 - 1, (ll)0);
            if(a[i][m / 2 + 1] == '1' && cnt1 != 0 && cnt2 != 0) {
                ll cnt = min(cnt1, cnt2);
                v.push_back(cnt);             
            }
        }
        sort(v.begin(), v.end(), cmp);
        if(v.size() == 0) {
            if(ans % 2 == 0) cout << "Bob" << "\n";
            else cout << "Alice" << "\n";
        } 
        else if(ans % 2 == 0) {
            if(v.size() == 1) cout << "Alice" << "\n";
            // else {
            //     ll cnt = 0;
            //     for(auto i : v) cnt += i.cnt - 1;
            //     if(v.size() % 2 == 0 && cnt % 2 == 0 || v.size() % 2 == 1 && cnt % 2 == 1) cout << "Bob" << "\n";
            //     else cout << "Alice" << "\n";
            // }
            else if(v.size() % 2 == 1) {
                for(ll i = 0; i < v.size(); i ++ ) {
                    if()
                } 

            }
            else cout << "Bob" << "\n";
        }
        else if(ans % 2 == 1) {
            if(v.size() == 1 && v[0] == 1) cout << "Alice" << "\n";
            else if(v.size() == 1 && v[0] != 1) cout << "Bob" << "\n";
            else {
                // ll cnt = 0;
                // for(auto i : v) cnt += i.cnt - 1;
                // if(v.size() % 2 == 0 && cnt % 2 == 0 || v.size() % 2 == 1 && cnt % 2 == 1) cout << "Alice" << "\n";
                // else cout << "Bob" << "\n";
                if(v.size() % 2 == 1) cout << "Bob" << "\n";
                else cout << "Alice" << "\n";
            }   
        } 
    }
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