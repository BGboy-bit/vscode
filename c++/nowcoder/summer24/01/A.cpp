#include<bits/stdc++.h>
#define int long long
using ll = long long;
using PII = std::array<int,2>;
using namespace std;
const ll INF = 2E18+10;
typedef long long LL;

int q;
ll power(ll a,ll b,ll m) //快速幂求a^b%m; 
{
    a%=q;
	ll ans=1;
	while(b)
	{
		if(b&1) ans=ans*a%q;
		b>>=1;
		a=a*a%q;
	}
	return ans;
}
const int MAXN = 5050; // 最大可以计算的 n 的值

vector<vector<int>> comb(MAXN + 1, vector<int>(MAXN + 1, 0));

// 计算组合数，取模
void calculate_combinations() {
    for (int n = 0; n <= MAXN; ++n) {
        for (int k = 0; k <= n; ++k) {
            if (k == 0 || k == n) {
                comb[n][k] = 1; // C(n, 0) = C(n, n) = 1
            } else {
                comb[n][k] = (comb[n - 1][k - 1] + comb[n - 1][k]) % q; // 递推关系式，取模
            }
        }
    }
}

// 查询组合数，取模
int get_combination(int n, int k) {
    if (k > n || k < 0) {
        return 0; // 如果 k 超过 n 或者小于 0，则返回 0
    }
    return comb[n][k];
}

void SINGLE_TEST()
{
    int n, m;
    cin>> n >> m >> q;
    calculate_combinations();
    ll ans = 0;
    for(int i = 1;i <= n;i ++ ) {
        /* 
        从 n 中选 i 个数作为子序列，每个数的二进制形式第一位必须为1，
        剩下的 m - 1 位中每一位只有所有数在这位为1这种情况不行，
        及 2 ^ i - 1，在将2 ^ (m - 1)个这样的数相乘即为子序列的取法数
        */
        ll res = get_combination(n, i) * power(power(2, i, q) - 1, m - 1, q) % q; 
        /*
        序列中不作为子序列中的 n - i 个数除了第一位为0以外，剩下的 m - 1 位可以任意取0或者1
        */
        ll sum = power(2, m - 1, q) % q;
        res = res * power(sum, n - i, q) % q;
        ans += res;
        ans %= q;
    }
    cout<< ans <<"\n";
}

signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);

    int SAMPLES = 1;
	// cin>>SAMPLES;
    while(SAMPLES--) SINGLE_TEST();
}

