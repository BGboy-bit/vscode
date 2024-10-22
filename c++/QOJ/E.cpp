#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mp[5050][5050];
ll deg[5050];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    string str;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> str;
        str = "!" + str;
        for(ll j = 1; j < str.size(); j ++ ) {
            if(str[j] == '1') {
                mp[i][j] = 1;
                deg[i] ++ ;
            }
        }
    }
    set<ll> s;
    vector<ll> ans;
    for(ll i = 1; i <= n; i ++ ) {
        if(deg[i] > 0) {
            s.insert(i);
        }
    }
    ll ac = 1;
    for(ll i = 1; i <= 3; i ++ ) {
        if(s.size() == 0) {
            ac = 0; break;
        }
        ll maxx = 0, idx;
        for(auto j : s) {
            if(maxx < deg[j]) {
                maxx = deg[j]; idx = j;
            }
        }
        ans.push_back(idx);
        for(ll j = 1; j <= n; j ++ ) {
            bool ff = 0;
            for(ll k = 1; k <= n; k ++ ) {
                if(mp[j][k] && !mp[idx][k]) {
                    ff = 1; break;
                }
            }
            if(!ff && s.find(j) != s.end()) {
                s.erase(j);
            }
        }
    }
    if(!ac) {
        cout << "NOT FOUND\n";
    } else {
        for(auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";
    }

    return 0;
}