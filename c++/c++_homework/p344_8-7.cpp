#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 0;//¶à×éÊäÈë

class Point {
private :
    db x, y;
public :
    Point& operator=(Point &p) {
        x = p.x; y = p.y;
        return *this;
    }
    Point& operator++() {
        x ++ ; y ++ ;
        return *this;
    }
    Point& operator--() {
        x -- ; y -- ;
        return *this;
    }
    Point operator++(int) {
        Point ol = *this;
        ++ (*this);
        return ol;
    }
    Point operator--(int) {
        Point ol = *this;
        -- (*this);
        return ol;
    }
    friend istream& operator>>(istream& is, Point &p) {
        is >> p.x >> p.y;
        return is;
    }
    friend ostream& operator<<(ostream& os, const Point &p) {
        os << "p(" << p.x << ", " << p.y << ") ";
        return os;
    }
};

void Solve() {
    Point p;
    cout << "p(x, y) : ";
    cin >> p;
    cout << p;
    cout << "-> p ++ -> " << p++ << " -> ";
    cout << "p -- -> " << p-- << " -> ";
    cout << "++ p -> " << ++p << " -> ";
    cout << "-- p -> " << --p;
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