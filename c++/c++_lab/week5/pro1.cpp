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

class Location {
private :
    db x, y;
public :
    Location(int X, int Y) : x(X), y(Y) {}
    db getX() {return x;}
    db getY() {return y;}
    friend db Dis1(Location &A, Location &B) {
        return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
    }
};

void Solve() {
    Location A(-1, -2);
    Location B(-1, 4);
    db d1 = sqrt((A.getX() - B.getX()) * (A.getX() - B.getX()) + (A.getY() - B.getY()) * (A.getY() - B.getY()));
    db d2 = Dis1(A, B);
    cout << "成员函数计算的距离为：" << d1 << "\n";
    cout << "友元函数计算的距离为：" << d2 << "\n";
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