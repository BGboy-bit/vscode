#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI=acos(-1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 0;//多组输入

//圆形
void cir() {
    cout << "请输入半径的值" << "\n"; 
    db r; cin >> r;
    cout << "半径为" << r << "的圆的面积为" << r * r * PI << "\n"; 
}

//长方形
void rect() {
    cout << "请输入长和宽的值" << "\n"; 
    ll a, b; cin >> a >> b;
    cout << "长和宽分别为" << a << "、" << b << "的长方形的面积的值为" << a * b << "\n";
}

//正方形
void squ() {
    cout << "请输入边长的值" << "\n"; 
    ll a; cin >> a;
    cout << "边长为" << a << "的正方形的面积的值为" << a * a << "\n";
}

void Solve() {
    cout << "圆形面积请输入1, 长方形面积请输入2, 正方形面积请输入3" << "\n";
    ll n; cin >> n;
    if(n == 1) cir();
    else if(n == 2) rect();
    else squ();
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