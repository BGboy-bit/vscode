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

class Object {
private :
    db weight;
public :
    Object(db we) {
        weight = we;
        cout << "call Object" << "\n";
    }
    db getWeight() {
        return weight;
    }
};

class Box : public Object {
private :
    db height, width;
public : 
    Box(db we, db h, db wi) : Object(we) {
        height = h; width = wi;
        cout << "call Box" << "\n";
    }
    db getHeight() {
        return height;
    }
    db getWidth() {
        return width;
    }
    ~Box() {
        cout << "destroy Box" << "\n";
    }
};

void Solve() {
    Box b(11.1, 170.1, 66.6);
}


signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}