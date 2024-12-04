#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    string s; cin >> s; 
    ll n = s.size(); s = " " + s;
    vector<vector<ll>> a(26, vector<ll>(n + 1)), b(26); 
    string ord;
    vector<ll> orr(26);
    for(ll i = 1; i <= n; i ++ ) {
        for(ll j = 0; j < 26; j ++ ) {
            a[j][i] = a[j][i - 1];
            if(s[i] - 'a' == j) {
                a[j][i] ++ ; b[j].push_back(i);
            }
        }
    }
    for(ll i = n; i >= 1; i -- ) {
        if(a[s[i] - 'a'][i] == a[s[i] - 'a'][n] && orr[s[i] - 'a'] == 0) {
            ord.push_back(s[i]); 
        }
    }
    for(ll i = 0; i < ord.size(); i ++ ) {
        orr[ord[i] - 'a'] = ord.size() - i;
    }
    vector<ll> c(26); // 26个字符在初始串中出现次数
    ll sum = 0;       // 初始串大小
    for(ll i = 0; i < 26; i ++ ) {
        if(!a[i][n]) continue;
        if(orr[i] == 0 || a[i][n] % orr[i] != 0) {
            cout << "-1\n"; return ;
        }
        c[i] = a[i][n] / orr[i];
        sum += c[i]; 
    }
    for(ll i = 0; i < 26; i ++ ) {
        if(a[i][sum] != c[i]) {
            cout << "-1\n"; return ;
        }
    }
    reverse(ord.begin(), ord.end());
    string s1 = s.substr(1, sum), t = "";
    for(ll i = 0; i < ord.size(); i ++ ) {
        t = t + s1;
        string s2;
        for(ll j = 0; j < s1.size(); j ++ ) {
            if(s1[j] != ord[i]) {
                s2.push_back(s1[j]);
            }
        }
        s1 = s2;
    }
    t = " " + t;
    if(t != s) {
        cout << "-1\n";
    } else {
        cout << s.substr(1, sum) << " " << ord << "\n";
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