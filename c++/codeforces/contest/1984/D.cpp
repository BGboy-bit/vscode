#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    string s; cin >> s;
    ll sz = s.size();
    s = "!" + s;
    char c;
    for(ll i = 1; i <= sz; i ++ ) {
        if(s[i] != 'a') {
            c = s[i]; break;
        }
    }
    vector<pair<ll, ll>> a;
    ll cur = 0;
    bool ff = 0;
    string ss;
    for(ll i = 1; i <= sz; i ++ ) {
        if(s[i] == 'a') {
            cur ++ ; ff = 0;
        } else if(s[i] == c) {
            a.push_back({i, cur}); ff = 1;
        } else {
            if(!ff) {
                cout << "1\n"; return ;
            }
        }
    }
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