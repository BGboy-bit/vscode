#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 1e5 + 10;
ll n, m, l, r, x;

//�������ǰ׺�ͼ�Ϊԭ����
ll b[MAX];

//������鼴��Ǵ�i��ʼ�ĺ���ÿ��a[]����a[i]�Ļ����ϼ���b[i]����b[r + 1] -= x����Ǵ�'r + 1'��ʼ���ټ���x
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
        //��a���������ת��Ϊ��ֵĲ������
        insert(l, r, x);
    }
    for(ll i = 1; i <= n; i ++ ) {
        b[i] += b[i - 1];
        cout << b[i] << " ";
    }
    return 0;
}