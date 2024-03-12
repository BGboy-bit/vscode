#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 1e5 + 10;
ll n, m, l, r, x;

//差分数组前缀和即为原数组
ll b[MAX];

//差分数组即标记从i开始的后面每个a[]都在a[i]的基础上加上b[i]，“b[r + 1] -= x”标记从'r + 1'开始不再加上x
void insert(ll l, ll r,ll x) {
    b[l] += x;
    b[r + 1] -= x; 
} 

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> x;
        insert(i, i ,x);
    }
    while(m -- ) {
        cin >> l >> r >> x;
        //把a数组的输入转化为差分的插入操作
        insert(l, r, x);
    }
    for(ll i = 1; i <= n; i ++ ) {
        b[i] += b[i - 1];
        cout << b[i] << " ";
    }
    return 0;
}