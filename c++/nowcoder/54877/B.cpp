#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string str;
    cin >> str;
    bool f = 0;
    for(ll i = 0; i < str.length() - 2; i ++ ) {
        if(str[i] == 'l') {
            if((str[i + 1] == 'o' || str[i + 1] == 'v') && str[i + 2] == 'e' || str[i + 1] == 'o' && str[i + 2] == 'v') {
                f = 1;
                break;
            }
            
        }
        else if(str[i] == 'o') {
            if(str[i + 1] ==  'v' && str[i + 2] == 'e') {
                f = 1;
                break;
            }
        }
    }
    if(f) cout << "YES";
    else cout << "NO";
    return 0;
}