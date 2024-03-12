#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 0;//∂‡◊È ‰»Î

 class dataType {
       public : 
            dataType(const string &str) {
                if(isdigit(str[0]) != 0) {
                    bool ff = 0;
                    for(auto c : str) {
                        if(c == '.') {
                            cout << str << " is a double data" << "\n";
                            ff = 1;
                        }
                    }
                    if(!ff) cout << str << " is a int data" << "\n";
                }
                else {
                    if(str.length() > 1) cout << str << " is a string data" << "\n";
                    else cout << str << " is a char data" << "\n"; 
                }
            }
};

void Solve() {
    string str; cin >> str;
    dataType s(str);
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}