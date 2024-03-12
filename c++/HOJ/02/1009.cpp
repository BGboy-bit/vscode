#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int inf = 0x3f3f3f3f;
const int MAX = 2e5 + 10;

void Solve() {
    ll ans = 0;
    string str;
    cin >> str;
    for(ll i = 0; i < str.length(); i ++ ) {
        if(str[i] == str[i - 1]) {
            for(ll j = i; j < str.length(); j ++ ) {
                if(str[j] == str[j - 1]) ans ++ ;
                else {
                    i = j - 1;
                    break;
                }
                if(j == str.length() - 1) i = str.length();
            }
        }
    }
    cout << ans << "\n";
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