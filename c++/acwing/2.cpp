// 2. 01��������
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 1010;
ll f[MAX][MAX];//����ֵ
ll v[MAX];// ���
ll w[MAX];// ��ֵ

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll m, n;
    cin >> n >> m;
    for(ll i = 1; i <= n; i ++ ) cin >> v[i] >> w[i];
    for(ll i = 1; i <= n; i ++ ) {
        for(ll j = 0; j <= m; j ++ ) {
            f[i][j] = f[i - 1][j];
            if(j >= v[i]) f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
        }
    }
    cout << f[n][m] << "\n";
    return 0;
}