#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n,c,k;
    cin >> n >> c >> k;
    string str;
    cin >> str;
    vector<bool>s(1ll << c);            //用状压01的方式记录每k段字符串出现过的字母种类 如A为01 B为10 AB则为11

    vector<int>pos(c,-1);         //记录所有字母的最近出现位置 用于快速求数组s
    for(int i = 0;i < k - 1;++i){         //预处理 pos
        pos[str[i] - 'A'] = i;
    }
    for(int i = k - 1;i < n;++i){
        pos[str[i] - 'A'] = i;
        int mask = 0;
        for(int j = 0;j < c;++j){
            if(pos[j] >= i - k + 1)        //如果这个字母出现的位置在[i - k + 1,i]内，则说明在这段中出现了，把他记录下来
                mask |= (1 << j);
        }
        s[mask] = 1;                       //这段出现的字母全记下来后，置为true 说明存在这样着一段有这几种字母子串
    }

    s[1 << (str[n - 1] - 'A')] = 1;        //因为末尾一定是要成为case的，所以单独拉出来置为true，也就是说末尾一定是答案字母中的其中一个字母
    vector<bool>bad(1ll << c);          //存不合法的情况

    for(int i = (1 << c) - 1;i >= 0;--i){
        bad[ ((1ll << c) - 1) ^ i ] = s[i];     //((1ll << c) - 1) ^ i就是i的补集，如果这个字母集合为s[i]的补集以及补集的子集，则说明这个集合一定没出现过s[i]段中的任何字母，其一定是非法的
    }

    for(int i = (1 << c) - 1;i >= 0;--i){
        if(bad[i]){                         //这里是把非法集合的所有子集都给找出来置为1，因为子集肯定比他的父亲小，为了把所有子集找出来，一定要从大到小遍历
            for(int j = 0;j < c;++j){
                if(i & (1ll << j)){
                  bad[i - (1ll << j)] = 1;
                }
            }
        }
    }

    int ans = c;
    for(int i = 1;i < (1 << c);++i){
        if(!bad[i]) {                       //把不合法的找出来后，剩下的一定是合法的，我们找其出现字母种类最小的即可
            ans = min(ans,(int)__builtin_popcount(i));      //__builtin_popcount()为内置函数，用于数一个数以二进制表示时出现1的个数
        }
    }

    cout << ans << endl;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	ll n; cin >> n;
	while(n -- ) {
		solve();
	}
	return 0;
}