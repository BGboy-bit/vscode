#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    if(x1 >= x2 && x1 >= x3) {//22 33 23 32
        if(y1 >= y2 && y1 >= y3) cout << x1 + y1 - max(y2, y3) - max(x2, x3) + 1 << "\n"; 
        else if(y2 >= y1 && y3 >= y1) cout << min(y2, y3) - max(x2, x3) + x1 - y1 + 1 << "\n";  
        else cout << -max(x2, x3) + x1 + 1 << "\n"; 
    }

    else if(x1 <= x2 && x1 <= x3) {// 11 44 14 41 
        if(y1 >= y2 && y1 >= y3) cout << -x1 + y1 - max(y2, y3) + min(x2, x3) + 1 << "\n";  
        else if(y2 >= y1 && y3 >= y1) cout << min(y2, y3) + min(x2, x3) - x1 - y1 + 1 << "\n";
        else cout << min(x2, x3) - x1 + 1 << "\n"; 
    }

    else if(y1 >= y2 && y1 >= y3) {// 34 43
        cout << y1 - max(y2, y3) + 1 <<"\n";
    }

    else if(y2 >= y1 && y3 >= y1) {// 12 21
        cout << min(y2, y3) - y1 + 1 <<"\n";
    }
    else //13 31 24 42 
        cout << "1" << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tt;
    cin >> tt;
    while(tt -- ) {
        Solve();
    }
    return 0;
}