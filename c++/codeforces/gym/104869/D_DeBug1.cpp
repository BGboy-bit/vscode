#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string a, b;

ll Solve2() {
    vector<string> aa, bb;
    for(ll i = 0; i < a.size(); i ++ ) {
        string s;
        for(ll j = i; j < a.size(); j ++ ) {
            s += a[j];
            aa.push_back(s);
        }
    }
    ll ans = 0;
    for(ll i = 0; i < b.size(); i ++ ) {
        string s;
        for(ll j = i; j < b.size(); j ++ ) {
            s += b[j];
            for(ll k = 0; k < aa.size(); k ++ ) {
                string ss = aa[k] + s;
                if(ss.size() % 2 == 1) continue;
                string s1 = ss.substr(0, ss.size() / 2), s2 = ss.substr(ss.size() / 2, ss.size() / 2);
                if(s1 == s2) {
                    ans ++ ;
                    cout << aa[k] << " " << s << "\n";
                }
            }
        }
    }
   return ans;
}

signed main() {
    cin >> a >> b;
    cout << Solve2() << "\n";
}