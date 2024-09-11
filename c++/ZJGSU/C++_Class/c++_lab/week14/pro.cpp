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
    A& operator *();
private:
	A* point;
	int* count; //引入应用计数, 注意此处不能为int count; 思考一下原因
};


share::share() {
    point = new A();
    count = new int(1);
}
share::share(A* p1) {
    point = p1;
    count = new int(1);
}
share::~share() {
    (*count) -- ;
    if (*count == 0) {
        delete point;
        delete count;
        // std::cout << "begin to delete share" << "\n";
    }
}

share::share(share& t2) {
    // this->point = new A(*(t2.point));
    // t2.point = new A();
    this->point = t2.point;
    this->count = t2.count;
    (*t2.count) ++ ;
}

share& share::operator=(share& t2) {
    if (this != &t2) {
        (*count) -- ;
        if (*count == 0) {
            delete this->point;
            delete this->count;
            // cout << "begin to delete share" << "\n";
        }
        this->point = t2.point;
        this->count = t2.count;
        (*count) ++ ;   
     }
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
	cout << "sp->n is :" << sp->n << endl;
	share sp2(sp);
	sp2->n = 20;
	cout << "sp->n is :" << sp2->n << endl;	
    share sp3;
	sp3 = sp2;
	sp3->n = 30;
	cout << "sp->n is :" << sp2->n << endl;
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