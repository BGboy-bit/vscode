#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string s; cin >> s;
    ll n = s.size(); s = " " + s;
    ll head = 1, len = 1;
    vector<ll> nxt(n + 1);
    cout << "1 1\n";
    for(ll i = 2; i <= n;i ++ ) {
        if(s[i] > s[head]) {
            head = i, len = 1;
            cout << head << " " << head << "\n";
            continue;
        }
        while(nxt[len] != 0 && s[head + nxt[len]] < s[i]) {
            head = head + len - nxt[len];
            len = nxt[len];
        }
        if(s[head + nxt[len]] == s[i]) {
            nxt[len + 1] = nxt[len] + 1;
            len ++;
        } else if(s[head + nxt[len]] > s[i]) {
            nxt[++len] = 0;
        }
        cout << head << " " << head + len - 1 << "\n";
    }
    return 0;
}