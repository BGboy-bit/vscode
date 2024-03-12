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

class Complex {
    private :
        db real_num;
        db ima_num;
    public : 
        Complex(db rn, db in);
        Complex(db rn);
        void add(Complex c2);
        void show();
};

Complex::Complex(db rn) : real_num(rn) {
    ima_num = 0; cout << "Complex构造函数成功调用!" << "\n";
}

Complex::Complex(db rn, db in) : real_num(rn), ima_num(in) {
    cout << "Complex构造函数成功调用!" << "\n";
};

void Complex::add(Complex c2) {
    real_num += c2.real_num;
    ima_num += c2.ima_num;
}

void Complex::show() {
    cout << real_num << "+" << ima_num << "i" << "\n";
}

void Solve() {
    Complex c1(3, 5);
    Complex c2 = 4.5;
    c1.add(c2);
    c1.show();
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