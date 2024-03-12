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

class Complexd {
private :
    db rel, ima;
public :
    Complexd() {rel = 0; ima = 0;}
    Complexd(db r, db i) : rel(r), ima(i) {}
    Complexd(const Complexd &com) {
        ima = com.ima; rel = com.rel;
    }
    Complexd& operator=(Complexd &com);
    friend Complexd operator+(const Complexd &c1, const Complexd &c2);
    friend Complexd operator-(const Complexd &c1, const Complexd &c2);
    friend Complexd operator*(const Complexd &c1, const Complexd &c2);
    friend Complexd operator/(const Complexd &c1, const Complexd &c2);
    friend Complexd operator+(const Complexd &c1, db d);
    friend istream& operator>>(istream &is, Complexd &com);
    friend ostream& operator<<(ostream &os, const Complexd &com);
};

Complexd& Complexd::operator=(Complexd &com) {
    this->rel = com.rel; this->ima = com.ima;
    return *this;
}
Complexd operator+(const Complexd &c1, const Complexd &c2) {
    Complexd com(0, 0);
    com.rel = c1.rel + c2.rel; com.ima = c1.ima + c2.ima;
    return com;
}
Complexd operator-(const Complexd &c1, const Complexd &c2) {
    Complexd com(0, 0);
    com.rel = c1.rel - c2.rel; com.ima = c1.ima - c2.ima;
    return com;
}
Complexd operator*(const Complexd &c1, const Complexd &c2) {
    Complexd com(0, 0);
    com.rel = c1.rel * c2.rel - c1.ima * c2.ima; 
    com.ima = c1.ima * c2.rel + c1.rel * c2.ima;
    return com;
}
Complexd operator/(const Complexd &c1, const Complexd &c2) {
    Complexd com(0, 0);
    com.rel = (c1.rel * c2.rel + c1.ima * c2.ima) / (c2.ima * c2.ima + c2.rel + c2.rel); 
    com.ima = (c1.ima * c2.rel - c1.rel * c2.ima) / (c2.ima * c2.ima + c2.rel + c2.rel);
    return com;
}
Complexd operator+(const Complexd &c1, db d) {
    Complexd com(0, 0);
    com.rel = c1.rel + d; com.ima = c1.ima;
    return com;
}
istream& operator>>(istream &is, Complexd &com) {
    is >> com.rel >> com.ima;
    return is;
}
ostream& operator<<(ostream &os, const Complexd &com) {
    if(com.rel != 0) {
        if(com.ima > 0) os << com.rel << " + " << com.ima << "i";
        else if(com.ima == 0) os << com.rel;
        else if(com.ima < 0) os << com.rel << " - " << fabs(com.ima) << "i";
    }
    else os << com.ima;
    return os;
}
void Solve() {
    Complexd c1, c2;
    cout << "c1(实部 虚部): ";
    cin >> c1;
    cout << "c2(实部 虚部): ";
    cin >> c2;
    cout << "c1 = " << c1 << "\n" << "c2 = " << c2 << "\n";
    cout << "c1 + c2 = " << c1 + c2 << "\n";
    cout << "c1 - c2 = " << c1 - c2 << "\n";
    cout << "c1 * c2 = " << c1 * c2 << "\n";
    cout << "c1 / c2 = " << c1 / c2 << "\n";
    cout << "double = ";      
    db d; cin >> d;
    cout << "c1 + d = " << c1 + d << "\n";
    
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
