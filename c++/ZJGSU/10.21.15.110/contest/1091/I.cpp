#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll inf = 1000000000;
const int mod = 998244353;
const int MAX = 1e5 + 10;

ll nxt[MAX], dp[20], ndp[20];

void Solve() {
    ll n, k; cin >> n >> k;
    string pat; cin >> pat;

    nxt[0] = -1; 
    for(ll i = 1, j = -1; i < pat.size(); i ++ ) {
        while(j != -1 && pat[i] != pat[j + 1]) j = nxt[j];
        if(pat[i] == pat[j + 1]) nxt[i] = nxt[ ++ j] ; 
        if(pat[i + 1] != pat[j + 1] || pat[i] != pat[j]) nxt[i] = j;
    }
    dp[0] = 1;
    while(n -- ) {
        string txt; cin >> txt;
        ll x = 1, y = 1;
        bool ff = 0;
        for(ll i = 0, j = -1; i < txt.size(); i ++ ) {
            if(txt[i] != pat[j + 1]) {
                if(!ff) {
                    x = max(x, j + 1);
                    ff = 1;
                } else {
                    y = max(y, j + 1);
                }
            }
            while(j != -1 && txt[i] != pat[j + 1]) j = nxt[j];
            if(txt[i] == pat[j + 1]) j ++ ;
            if(!ff) {
                x = max(x, j + 1);
            } else {
                y = max(y, j + 1);
            }
        }
        for(ll i = 0; i <= k; i ++ ) {
            ndp[i] = dp[i] * x;
            if(i) {
                ndp[i] = max(ndp[i], dp[i - 1] * y);
            }
        }
        swap(dp, ndp);
        for(ll i = 0; i <= k; i ++ ) {
            if(dp[i] > inf) {
                cout << "-1\n"; return ;
            }
        }
    }
    ll ans = 0;
    for(ll i = 0; i <= k; i ++ ) {
        ans = max(ans, dp[i]);
    }
    cout << ans << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    // cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}