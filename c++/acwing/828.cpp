#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 1e5 + 10;
int stk[MAX], tt;

int main() {
    ll m;
    cin >> m;
    while( m -- ) {
        string op;
        cin >> op;
        if(op == "push") {
            ll x;
            cin >> x;
            stk[ ++ tt] = x;
        }
        else if(op == "pop") tt -- ;
        else if(op == "empty") {
            if(tt == 0) cout << "YES" << "\n";
            else cout << "NO" << "\n";
        }
        else if(op == "query") cout << stk[tt] << "\n";
    }
    return 0;
}
