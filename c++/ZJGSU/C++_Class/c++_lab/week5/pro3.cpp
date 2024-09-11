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

class MyClass {
private :
	const double pi = acos(-1);
	static int number;
	string name;
public:
	MyClass();
    MyClass(string name);
    ~MyClass();
    MyClass (const MyClass& s);

    void print() const;
    static int getNumber();
};
int MyClass::number = 0;
MyClass::MyClass() : name("zhu") {number ++ ;}
MyClass::MyClass(string str) : name(str) {number ++ ;}
MyClass::~MyClass() {number -- ;}
MyClass::MyClass(const MyClass& s) {
    name = s.name;
    number ++ ;
}
void MyClass::print() const {cout << name << "\n";}
int MyClass::getNumber() {return number;}

void Solve() {
    MyClass mc1;
	MyClass mc2("zhang");
 
	cout << MyClass::getNumber() << endl;

	MyClass mc3(mc2);
	//mc3.print();

	const MyClass mc4("li");
	mc4.print();
	cout << MyClass::getNumber() << endl;

	MyClass * pm = new MyClass[6];
	cout << MyClass::getNumber() << endl;

	if(nullptr != pm) {
        delete[] pm;
        pm = nullptr;
    }

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