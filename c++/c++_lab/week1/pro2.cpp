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

//Բ��
void cir() {
    cout << "������뾶��ֵ" << "\n"; 
    db r; cin >> r;
    cout << "�뾶Ϊ" << r << "��Բ�����Ϊ" << r * r * PI << "\n"; 
}

//������
void rect() {
    cout << "�����볤�Ϳ��ֵ" << "\n"; 
    ll a, b; cin >> a >> b;
    cout << "���Ϳ�ֱ�Ϊ" << a << "��" << b << "�ĳ����ε������ֵΪ" << a * b << "\n";
}

//������
void squ() {
    cout << "������߳���ֵ" << "\n"; 
    ll a; cin >> a;
    cout << "�߳�Ϊ" << a << "�������ε������ֵΪ" << a * a << "\n";
}

void Solve() {
    cout << "Բ�����������1, ���������������2, ���������������3" << "\n";
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