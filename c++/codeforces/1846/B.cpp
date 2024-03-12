#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

string str[3];
bool Check(ll i, ll j) {
    if(str[0][j] == str[1][j] && str[0][j] == str[2][j] && str[1][j] == str[2][j]) return true;
    else if(str[i][0] == str[i][1] && str[i][0] == str[i][2] && str[i][1] == str[i][2]) return true;
    else if(str[0][0] == str[1][1] && str[0][0] == str[2][2] && str[1][1] == str[2][2] && i == j) return true;
    else if(str[0][2] == str[1][1] && str[0][2] == str[2][0] && str[2][0] == str[1][1] && (i == 0 && j == 2 || i == 1 && j == 1 || i == 2 && j == 0)) return true;
    return false;
}

void Solve() {
    cin >> str[0] >> str[1] >> str[2];
    bool ff = 1;
    for(ll i = 0; i < 3; i ++ ) {
        for(ll j = 0; j < 3; j ++ ) {
            if(str[i][j] == '.') continue;
            if(Check(i, j)) {
                ff = 0;
                cout << str[i][j] << "\n";
                break;
            }
        }
        if(!ff) break;
    }
    if(ff) cout << "DRAW" << "\n";
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