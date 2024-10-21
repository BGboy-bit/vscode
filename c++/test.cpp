#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    string s; cin >> s;
    ll sz = s.size();
    s = "!" + s;
    vector<ll> pos;
    for(ll i = 1; i <= sz; i ++ ) {
        if(s[i] != 'a') pos.push_back(i);
    }
    if(pos.size() == 0) {
        cout << sz - 1 << "\n"; return ;
    }
    ll p = pos.size();
    ll ans = 0;
    for(auto res = 1; res <= p; res ++ ) {
        bool ac = 1;
        for(ll i = res; i < p; i ++ ) {
            if(s[pos[i]] != s[pos[i - res]] || i % res != 0 && pos[i] - pos[i - res] != pos[i - 1] - pos[i - res - 1]) {
                ac = 0; break;
            } 
        }
        if(!ac) continue;

        ll l = pos[0], r = sz - pos[p - 1];
        ll minn = sz;
        for (ll i = res; i < p; i += res) {
            minn = min(minn, pos[i] - pos[i - 1] - 1);
        }
        for (ll i = 0; i < l; i ++ ) {
            ll ss = max(0ll, min(r + 1, minn - i + 1));
            ans += ss;
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

