//����ջ
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int MAX = 3e6 + 10;
ll a[MAX];
ll f[MAX];// ���������
ll n;
stack<ll> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(ll i = 1; i <= n; i ++ ) cin >> a[i];
    for(ll i = n; i >= 1; i -- ) {
        while(!s.empty() && a[s.top()] <= a[i]) s.pop(); //�ϸ���ڣ�Ҫ�ӵȺ�
        f[i] = (s.empty() ? 0 : s.top());
        s.push(i);
    }
    for(ll i = 1; i <= n; i ++ ) cout << f[i] << " ";
    return 0;
}