#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int inf = 0x3f3f3f3f;
const int mod = 998244353;
const int MAX = 1e6 + 10;

ll n;
ll a[MAX], b;
struct node {
    ll l, r;
    bool ff;//标记(a, b) or (b, a),判断是否反序
}lst[MAX], res;
ll sum;//初始值
ll ans;//最大差值

bool cmp(node u, node v) {
    return u.l < v.l;
}

void Solve() {
    cin >> n;
    for(ll i = 1; i <= n; i ++ ) cin >> a[i];
    ll cnt = 0;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> b;
        if(a[i] != b) {
            ll l = min(b, a[i]);
            ll r = max(b, a[i]);
            sum += r - l;
            lst[++ cnt] = {l, r, a[i] > b};
        }
    }
    sort(lst + 1, lst + cnt + 1, cmp);

    res = lst[1];
    for(ll i = 2; i <= cnt; i ++ ) {
        if(lst[i].r < res.r) {//包容
            if(res.ff != lst[i].ff) //反序
            ans = max(ans, lst[i].r - lst[i].l);   
        } else {//相交
            if(res.ff != lst[i].ff) //反序
            ans = max(ans, res.r - lst[i].l);
            res = lst[i];//相交则更新左起点，因为左边的部分已经没有用了
        }
    }
    cout << sum - ans * 2 << "\n";
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