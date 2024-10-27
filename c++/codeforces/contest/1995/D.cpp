#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n, c, k; cin >> n >> c >> k;
    string s; cin >> s; s = "!" + s;
    vector<ll> ac(1 << c);
    vector<ll> mp(c);
    for(ll i = 1; i < k; i ++ ) {
        mp[s[i] - 'A'] ++ ;
    }
    for(ll i = k; i <= n; i ++ ) {
        mp[s[i] - 'A'] ++ ; if(i > k) mp[s[i - k] - 'A'] -- ; 
        ll acc = 0;
        for(ll j = 0; j < c; j ++ ) {
            if(mp[j]) {
                acc += 1 << j;
            }
        }
        ac[((1 << c) - 1) ^ acc] = 1;
    }
    ac[((1 << c) - 1) ^ (1 << (s[n] - 'A'))] = 1;

    ll ans = 20;
    for(ll i = (1 << c) - 1; i >= 0; i -- ) {
        if(!ac[i]) {
            bitset<20> bt(i);
            ans = min(ans, (ll)bt.count());
        } else {
            for(ll j = 0; j < c; j ++ ) {
                if(i & (1 << j)) ac[i - (1 << j)] = 1;
            }
        }
    }
    cout << ans << "\n";
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