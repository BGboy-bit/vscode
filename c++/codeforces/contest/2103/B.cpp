#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n; cin >> n;
    string s; cin >> s;
    string s1;
    char ff = '0';
    if(s[0] == ff) 
        s1.push_back(ff);
    else {
        s1.push_back(ff + 1);
        ff = '1';
    }
    for(ll i = 1; i < n; i ++ ) {
        if(s[i] != ff) {
            ff = s[i];
            s1.push_back(ff);
        }
    }
    if(s1.size() == 1) {
        cout << n + (s1[0] == '0' ? 0 : 1) << "\n"; return ;
    }
    if(s1.size() == 2) {
        cout << n + 1 << "\n"; return ;
    } 
    if(s1.size() == 3) {
        cout << n + s1.size() - 2 << "\n"; return ;
    } 
    if(s1.size() >= 4) {
        cout << n + s1.size() - (s1[0] == '0' ? 1 : 0) - 2 << "\n";
    }
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