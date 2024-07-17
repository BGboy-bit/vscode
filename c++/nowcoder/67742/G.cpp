#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 5e5 + 10;
ll n, m, l, x, y, k;
ll a[MAX];
ll ans;

struct segment_tree {
    struct Tree {
        ll l, r;
        ll sum;
        ll lazy;
    } tr[MAX * 4];
    void build(ll i, ll l, ll r) {
        tr[i] = {l, r, 0, 0};
        if (l == r) {
            tr[i].sum = a[l];
            return;
        }
        ll mid = (l + r) >> 1;
        build(i << 1, l, mid);
        build(i << 1 | 1, mid + 1, r);
        tr[i].sum = tr[i << 1].sum + tr[i << 1 | 1].sum;
    }
    void pushdown(ll i) {
        if (tr[i].lazy) {
            tr[i << 1].sum += tr[i].lazy * (tr[i << 1].r - tr[i << 1].l + 1);
            tr[i << 1 | 1].sum += tr[i].lazy * (tr[i << 1 | 1].r - tr[i << 1 | 1].l + 1);
            tr[i << 1].lazy += tr[i].lazy;
            tr[i << 1 | 1].lazy += tr[i].lazy;
            tr[i].lazy = 0;
        }
    }
    void add(ll i, ll pos, ll k) { // 单点修改
        if (tr[i].l == tr[i].r) {
            tr[i].sum += k;
            return;
        }
        pushdown(i);
        ll mid = (tr[i].l + tr[i].r) >> 1;
        if (pos <= mid) add(i << 1, pos, k);
        else add(i << 1 | 1, pos, k);
        tr[i].sum = tr[i << 1].sum + tr[i << 1 | 1].sum;
    }

    void modify(ll i, ll l, ll r, ll k) { // 区间修改
        if (tr[i].l >= l && tr[i].r <= r) {
            tr[i].sum += k * (tr[i].r - tr[i].l + 1);
            tr[i].lazy += k;
            return;
        }
        pushdown(i);
        ll mid = (tr[i].l + tr[i].r) >> 1;
        if (l <= mid) modify(i << 1, l, r, k);
        if (r > mid) modify(i << 1 | 1, l, r, k);
        tr[i].sum = tr[i << 1].sum + tr[i << 1 | 1].sum;
    }

    ll search(ll i, ll l, ll r) { // 区间查询
        if (tr[i].l >= l && tr[i].r <= r) return tr[i].sum;
        pushdown(i);
        ll mid = (tr[i].l + tr[i].r) >> 1;
        ll sum = 0;
        if (l <= mid) sum += search(i << 1, l, r);
        if (r > mid) sum += search(i << 1 | 1, l, r);
        return sum;
    }

    ll query(ll i, ll pos) { // 单点查询
        if (tr[i].l == tr[i].r) return tr[i].sum;
        pushdown(i);
        ll mid = (tr[i].l + tr[i].r) >> 1;
        if (pos <= mid) return query(i << 1, pos);
        else return query(i << 1 | 1, pos);
    }
} ST;

int main() {
    ll t = 1; cin >> t;
    while (t--) {
        cin >> n >> m;
        for (ll i = 1; i <= n; i++) cin >> a[i];
        ST.build(1, 1, n);
        for (ll i = 1; i <= m; i++) {
            cin >> l;
            if(l == 1) {
            	cin >> x >> k;
                k -= ST.query(1, x);
            	ST.add(1, x, k);
            } else if (l == 2) {
                cin >> x >> y;
                cout << ST.search(1, x, y - 1) - ST.query(1, y) << "\n";
            }
            else if (l == 3) {
                cin >> x;
                cout << ST.query(1, x) << "\n";
            }
        }
    }
    return 0;
}
