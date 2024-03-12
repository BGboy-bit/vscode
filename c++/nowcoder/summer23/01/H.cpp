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
    bool ff;//���(a, b) or (b, a),�ж��Ƿ���
}lst[MAX], res;
ll sum;//��ʼֵ
ll ans;//����ֵ

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
        if(lst[i].r < res.r) {//����
            if(res.ff != lst[i].ff) //����
            ans = max(ans, lst[i].r - lst[i].l);   
        } else {//�ཻ
            if(res.ff != lst[i].ff) //����
            ans = max(ans, res.r - lst[i].l);
            res = lst[i];//�ཻ���������㣬��Ϊ��ߵĲ����Ѿ�û������
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