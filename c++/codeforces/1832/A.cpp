#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

map<char, int> mp;

void Solve() {
    string str;
    int cnt = 0;
    cin >> str;
    for(ll i = 0; i < str.length() / 2; i ++) {
       if(mp[str[i]] == 0) {
            cnt ++;
            mp[str[i]] = 1;
        }
    }
    if(cnt <= 1) cout << "NO" << "\n";
    else cout << "YES" << "\n";
    for(ll i = 0; i < str.length() / 2; i ++) {
       mp[str[i]] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}