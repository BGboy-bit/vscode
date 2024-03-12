#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 0;//多组输入

class Circle {
    public : 
        Circle(db r) : radius(r) {}
        void getArea() {
            cout << "半径为" << radius << "的圆的面积为" << radius * radius * PI << "\n";
        }
    private : 
        db radius = 0;
};

void Solve() {
    double r; cin >> r;
    Circle c(r);
    c.getArea();
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