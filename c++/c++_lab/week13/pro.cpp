#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 0;//¶à×éÊäÈë

class A {
public:
	A()	{ n = 0; }
	int n;
};

class share {
public:
	share();
	explicit share(A* p1);
	~share();
	share(share& t2);
	share& operator =(share& t2);
	A* operator ->();
    A& operator*();
private:
	A* point;
};

share::share() {
    point = new A();
}
share::share(A* p1) {
    point = p1;
}
share::~share() {
    if (point != nullptr) {
        delete point;
        cout << "begin to delete share" << "\n";
    }
}

share::share(share& t2) {
    this->point = new A(*(t2.point));
    t2.point = new A();
}

share& share::operator=(share& t2) {
    this->point = new A(*(t2.point));
    return *this;
}
A* share::operator ->() {
    return this->point;
}

A& share::operator*() {
    return *point;
}

void Solve() {
    share sp(new A());
	sp->n = 10;

	share sp2 = sp;
	cout << "sp2->n is :" << sp2->n << endl;
    // share sp(new A());
	// sp->n = 10;
	// share sp2 = sp;
	// cout << "sp2->n is :" << sp2->n << endl;
    // cout << "sp->n is :" << sp->n << endl;

    // A a;
    // share sp3(&a);
    // sp = sp3;
    // cout << "sp->n is :" << sp->n << endl;

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