#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI=acos(-1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 0;//��������

class stu {

    public: 
        //Ĭ�Ϲ��캯��
        stu(){name = "����"; age = 10;}
        //��ͨ���캯��(��Ա��ʼ���б�)
        stu(const string &Name, const ll &Age) : name(Name), age(Age) {}
        //��������
        ~stu();
        //��ӡ����
        void print();

    private: 
        string name = "";
        ll age = 0;
};

void Solve() {
    string Name;
    ll Age;
    cout << "������������"; cin >> Name;
    cout << "���������䣺"; cin >> Age;
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
    cout << "��������ִ��,ɾ��" << name << "����Ϣ" <<"\n";
}

void stu::print() {
        cout << "ͬѧ������Ϊ" << name << "," << "����Ϊ" << age << "\n";
}