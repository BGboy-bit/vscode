//参考https://blog.csdn.net/weixin_62486861/article/details/131600025?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522168878607616800185843832%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=168878607616800185843832&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-4-131600025-null-null.142^v88^control_2,239^v2^insert_chatgpt&utm_term=C.%20Vampiric%20Powers%2C%20anyone&spm=1018.2226.3001.4187
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

void Solve() {
    ll n;
    cin >> n;
    vector<ll> a(n + 1);
    for(ll i = 1; i <= n; i ++ ) cin >> a[i];
    ll cur = 0;//当前的前缀异或和
    vector<ll> pre(1 << 8);//存储前缀异或和
    pre[0] = 1;

    ll ans = 0;
    for(ll i = 1; i <= n; i ++ ) {
        cur ^= a[i];

        //1e5 * 1e5 会tle，甚至push_back也会卡
        // pre.push_back(cur);
        // for(auto x : pre) {
        //     ans = max(ans, x ^ cur);
        // }
        pre[cur] = 1;
        for(ll pp = 0; pp < (1 << 8); pp ++ ) {
            if(pre[pp] == 1) ans = max(ans, pp ^ cur);
        }

    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tt;
    cin >> tt;
    while( tt -- ) {
        Solve();
    }
    return 0;
}