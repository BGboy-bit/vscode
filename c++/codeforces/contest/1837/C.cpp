#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

string str;

void Solve() {
    cin >> str;
    if(str[0] == '?') str[0] = '0';
    for(ll i = 1;i < str.length(); i ++) {
        if(str[i] == '?') {
            if(str[i - 1] == '0') str[i] = '0';
            else str[i] = '1';
         }
    }
    cout << str << "\n";
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