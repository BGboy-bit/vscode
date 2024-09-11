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

class stu {

    public: 
        //默认构造函数
        stu(){name = "张三"; age = 10;}
        //普通构造函数(成员初始化列表)
        stu(const string &Name, const ll &Age) : name(Name), age(Age) {}
        //析构函数
        ~stu();
        //打印函数
        void print();

    private: 
        string name = "";
        ll age = 0;
};

void Solve() {
    string Name;
    ll Age;
    cout << "请输入姓名："; cin >> Name;
    cout << "请输入年龄："; cin >> Age;
    stu s1;
    s1.print();
    stu s2(Name, Age);
    s2.print();
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

stu::~stu() {
    cout << "析构函数执行,删除" << name << "的信息" <<"\n";
}

void stu::print() {
        cout << "同学的姓名为" << name << "," << "年龄为" << age << "\n";
}