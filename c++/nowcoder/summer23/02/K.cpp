#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 1e6 + 10;

ll n;
ll a[MAX], b[MAX];
ll dp[MAX][3];//1���ƣ�2������3����
void Solve() {
    cin >> n;
    for(ll i = 1; i <= n; i ++ ) cin >> a[i];
    for(ll i = 1; i <= n; i ++ ) cin >> b[i];

    for(ll i = 1; i <= n; i ++ ) {
        if(b[i] == 1) {//�и���
            dp[i][0] = dp[i - 1][0] + a[i - 1];//���Ƹ��ӵ����ֵ��Ϊ���������û�и���
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + a[i];//���Ӳ��������ֵ��Ϊ��߸���û������
            dp[i][2] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2])) + a[i + 1];//�������ƺ��Լ�����ճ����ˣ���Ҫ����ߵĸ��ӵ��������ȡ���ֵ
        } else {//û�и���
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);//��֤�Լ�����û�и���
            dp[i][1] = dp[i][2] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));//��һ��״̬ȡ���ֵ
        }
    }
    cout << max(dp[n][0], dp[n][1]) << "\n";//���һ������ֻ�����ƻ���
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    // cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}