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

void swap(ll x, ll y) {
    ll z = x;
    x = y; 
    y = z;
}

void swap(ll *x, ll *y) {
    ll z = *x;
    *x = *y;
    *y = z;
}

void swap1(ll &x, ll &y) {
    ll z = x;
    x = y;
    y = z;
}

void Solve() {
    ll a = 1, b = 2; cout << "��ʼֵ��a = " << a << "," << "b = " << b << "\n";
    a = 1, b = 2; swap(a, b); cout << "��ֵ�Ľ����a = " << a << "," << "b = " << b << "\n";
    a = 1, b = 2; swap(&a, &b); cout << "��ָ��Ľ����a = " << a << "," << "b = " << b << "\n";
    a = 1, b = 2; swap1(a, b); cout << "�����õĽ����a = " << a << "," << "b = " << b << "\n";
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