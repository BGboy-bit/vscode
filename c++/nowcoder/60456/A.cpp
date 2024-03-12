#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

ll vis[1010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s, t;
    cin >> s >> t;
    ll cnt = 0;
    ll res = 0;
    for(ll j = 0; j < s.length(); j ++ ) {
        for(ll i = j; i < s.length(); i ++ ) {
            if(s[i] == t[res]) {
                if(res == 0) {
                    if(vis[i] == 0) vis[i] = 1;
                    else break;
                } 
                res ++ ;
            }
            else res = 0;
            if(res == t.size()) {
                cnt ++ ;
                res = 0;
                
            } 
            if(i == s.length() - 1 && res != 0) i = -1;
        }
    }
    cout << cnt << "\n";
    return 0;
}