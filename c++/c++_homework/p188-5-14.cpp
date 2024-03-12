#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 0;//��������

class Car;
class Boat {
private : 
    ll weight;
public :
    Boat(ll wb) : weight(wb) {}
    friend void getTotalWeight(Boat& b, Car &c);
};

class Car {
private :
    ll weight;
public :
    Car(ll wc) : weight(wc) {}
    friend void getTotalWeight(Boat &b, Car &c);
};

void getTotalWeight(Boat &b, Car &c) {
    cout << "���ͳ���ͬ������Ϊ��" << c.weight + b.weight << "kg" << "\n";
}

void Solve() {
    cout << "�����봬��������";
    ll wb; cin >> wb;
    cout << "�����복��������";
    ll wc; cin >> wc;
    Boat b(wb); Car c(wc);
    getTotalWeight(b, c);
}


signed main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}