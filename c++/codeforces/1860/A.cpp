#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 1;//¶à×éÊäÈë

void Solve() {
    string str;
    cin >> str;
    if(str.length() == 2 && str == "()" || str.length() == 1) cout << "No" << "\n";
    else {
        cout << "Yes" << "\n";
        ll cnt1 = -1;
        for(ll i = 0; i < str.length(); i ++ ) {  
            if(cnt1 == 1 && str[i] == '(' || cnt1 == 0 && str[i] == ')') {
                for(ll j = 0; j < str.length() * 2; j ++) {
                    if(j % 2 == 0) cout << "(";
                    else cout << ")";
                }
                cout << "\n";
                return ;
            }
            if(str[i] == '(') cnt1 = 1;
            else cnt1 = 0;
        }
        for(ll i = 0; i < str.length() * 2; i ++ ) {
            if(i < str.length()) cout << "(";
            else cout << ")";
        }
        cout << "\n";
    }
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}