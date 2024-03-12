#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 1e5 + 10;
int val[MAX], l[MAX], r[MAX], idx;

void init() {
    l[1] = 0;
    r[0] = 1;
    idx = 2;
}

//函数为在k个数的右边插入一个值
void add(int k, int x) {
    val[idx] = x;
    l[idx] = k;
    r[idx] = r[k];
    l[r[k]] = idx;
    r[k] = idx;
    idx ++ ;
}

void remove(int k) {
    l[r[k]] = l[k];
    r[l[k]] = r[k];
}

int main() {
    init();
    int m;
    cin >> m;
    while( m -- ) {
        string op;
        cin >> op;
        if(op == "L") {
            int x;
            cin >> x;
            add(0, x);//0为头节点
        }
        else if(op == "R") {
            int x;
            cin >> x;
            add(l[1], x);//1为尾节点
        }
        else if(op == "D") {
            int k;
            cin >> k;
            remove(k + 1);       
        }
        else if(op == "IL") {
            int k, x;
            cin >> k >> x;
            add(l[k + 1], x);
        }
        else if(op == "IR") {
            int k, x;
            cin >> k >> x;
            add(k + 1, x);
        }
    }
    for(int i = r[0]; i != 1; i = r[i]) cout << val[i] << " ";
    return 0;
}