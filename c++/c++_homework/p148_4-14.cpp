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

class Tree {
    private : 
        ll ages;  
    public : 
        Tree(int = 0);
        void grow(int years);
        void age();
};

Tree::Tree(int ages) : ages(ages) {};

void Tree::grow(int years) {
    ages += years;
    cout << "Tree�ɹ������� " << years << " years" << "\n";
}

void Tree::age() {
    cout << "Tree������Ϊ " << ages << " years" << "\n";
}

void Solve() {
    Tree tree(1);
    tree.age();
    cout << "��������ΪTree���ϵ�����: ";
    int a; cin >> a;
    tree.grow(a);
    tree.age();
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

