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
bool multi = 0;

void Solve() {
    ll n; cin >> n;
    ll maxx = 0;
    vector<ll> ans;
    for(ll i = 0; i <= n; i ++ ) {
        for(ll j = i; j <= n; j ++ ) {
            for(ll k = j; k <= n; k ++ ) {
                vector<ll> b = {0, i, j, k};
                ll summ = 0;
                for(ll u = 1; u <= 3; u ++ ) {
                    for(ll v = u + 1; v <= 3; v ++ ) {
                        summ += 2 * (b[u] ^ b[v]);
                    }
                }
                if(maxx <= summ) {
                    if(maxx < summ) {
                        ans.clear();
                    }
                    maxx = summ;
                    ans.push_back(i), ans.push_back(j), ans.push_back(k);
                }
            }
        }
    }

    // cout << maxx << "\n" << ans.size() / 3 << "\n";
    ll cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for(ll i = 0; i < ans.size(); i += 3) {
        cout << ans[i] << " \n"[(i + 1) % 3 == 0];
        ll cnt = 0;
        if(ans[i] == ans[i + 1]) cnt ++ ;
        if(ans[i] == ans[i + 2]) cnt ++ ;
        if(ans[i + 1] == ans[i + 2]) cnt ++ ;
        if(cnt == 0) cnt0 ++ ;
        if(cnt == 1) cnt1 ++ ;
        if(cnt == 2) cnt2 ++ ;
    }
    cout << cnt0 << " " << cnt1 << " " << cnt2 << "\n";
    cout << cnt0 * 6 + cnt1 * 3 << "\n";
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