//Ïß¶ÎÊ÷
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int MAX = 5e5 + 10;
ll n,m,l,x,y,k;
ll a[MAX];
ll ans;
struct segment_tree {

    struct Tree {
        ll l,r;
        ll sum;
    }tr[MAX * 4];

    void build(ll i,ll l,ll r)
    {
        tr[i] = {l,r,0};
        if(l == r) 
        {
            tr[i].sum = a[l];
            return;
        }
        ll mid = l + r >> 1;
        build(i << 1,l,mid); build(i << 1 | 1,mid + 1,r);
    } 

    void add(ll i,ll dis,ll k)
    {
        if(tr[i].l == tr[i].r) 
        {
            tr[i].sum += k;
            return;
        }
        if(dis <= tr[i].r) add(i << 1,dis,k);
        else add(i << 1 | 1,dis,k);
        tr[i].sum = tr[i << 1].sum + tr[i << 1 | 1].sum;
    }
    ll search(ll i,ll l,ll r)
    {
        if(tr[i].l >= l && tr[i].r <= r) return tr[i].sum;
        if(tr[i].l < l && tr[i].r > r) return 0;
        ll sum = 0;
        if(tr[i * 2].r >= l) sum += search(i << 1,l,r);
        if(tr[i * 2 + 1].l <= r) sum += search(i << 1 | 1,l,r);
        return sum;
    }

    void modify(ll i,ll l,ll r,ll k)
    {
        if(tr[i].l >= l && tr[i].r <= r)
        {
            tr[i].sum += k;
            return;
        }    
        ll mid = tr[i].l + tr[i].r >> 1;
        if(l <= mid) modify(i << 1, l, r, k);
        if(r > mid)  modify(i << 1 | 1, l , r, k);
    }

    void query(ll i,ll dis)
    {
        ans += tr[i].sum;
        if(tr[i].l == tr[i].r) return;
        ll mid = tr[i].l + tr[i].r >> 1;
        if(dis <= mid) query(i << 1,dis);
        else query(i << 1 | 1,dis);
    }

}ST;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	ll t = 1;
//	cin >> t;
	while(t -- )
	{
        cin >> n >> m;
        for(ll i = 1;i <= n;i ++ ) cin >> a[i];
        ST.build(1,1,n);
        for(ll i = 1;i <= m;i ++ )
        {
            cin >> l;
            if(l == 1)
            {
                cin >> x >> y >> k;
                ST.modify(1, x, y, k);    
            }

            else if(l == 2)
            {
                ans = 0;
                cin >> x;
                ST.query(1, x);
                cout << ans << "\n";
            }
        }
	}
	return 0;
}