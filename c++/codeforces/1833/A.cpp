#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, ans;
string s, str;
unordered_map<string, bool> mp;

void Solve() {
    for(ll i = 0; i < s.length() - 1; i ++ ) {
        str += s[i];
        str += s[i + 1];
        if(mp[str] == 0) {
            ans ++;
            mp[str] = 1;
        }
        str.clear();
    }
    cout << ans << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T -- ) {
        cin >> n >> s;
        mp.clear();
        ans = 0;
        Solve();
    }
    return 0;
}