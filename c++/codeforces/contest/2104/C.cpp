#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n; cin >> n;
    string s; cin >> s; s = "!" + s;
    if(s[1] == s[n]) {
        cout << (s[n] == 'A' ? "Alice" : "Bob") << "\n"; return ;
    }
    if(s[n] == 'A' && s[n - 1] == 'A') {
        cout << "Alice\n"; return ;
    }
    if(s[n] == 'B') {
        for(ll i = 1; i < n; i ++ ) {
            if(s[i] == s[n]) {
                cout << (s[n] == 'A' ? "Alice" : "Bob") << "\n"; return ;
            }
        }
    }
    cout << (s[n] == 'A' ? "Bob" : "Alice") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1; cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}