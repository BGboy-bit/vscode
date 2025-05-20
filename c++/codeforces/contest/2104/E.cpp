#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n, k; cin >> n >> k;
    string s; cin >> s;
    vector<vector<ll>> nxt(k, vector<ll> (n + 2, n + 1));
    for(ll c = 0; c < k; c ++ ) {
        for(ll i = n - 1; i >= 0; i -- ) {
            nxt[c][i] = s[i] == 'a' + c ? i + 1 : nxt[c][i + 1];
        }
    }
    vector<ll> dp(n + 2, 0);
    for(ll i = n; i >= 0; i -- ) {
        dp[i] = 1e8;
        for(ll c = 0; c < k; c ++ ) {
            dp[i] = min(dp[i], dp[nxt[c][i]] + 1);
        }
    }
    ll q; cin >> q;
    while(q -- ) {
        string s1; cin >> s1;
        ll pos = 0;
        for(auto c : s1) {
            pos = nxt[c - 'a'][pos];
        }
        cout << dp[pos] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    Solve();
    return 0;
}