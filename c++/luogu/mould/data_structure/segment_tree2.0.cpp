//Ïß¶ÎÊ÷
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int MAX = 5e5 + 10;
ll n,m,l,x,y,k;
ll a[MAX];
ll ans;//å•ç‚¹æŸ¥è?¢çš„ç­”æ??
struct segment_tree {

    struct Tree {
        ll l,r;
        ll sum;
    }tr[MAX * 4];

    void build(ll i,ll l,ll r) {
        tr[i] = {l,r,0};
        if(l == r) 
        {
            tr[i].sum = a[l];
            return;
        }
        ll mid = l + r >> 1;
        build(i << 1,l,mid); build(i << 1 | 1,mid + 1,r);
        tr[i].sum = tr[i << 1].sum + tr[i << 1 | 1].sum;
    } 
    
    void Update(ll l,ll r,ll cl,ll cr,ll k) {
        
    }

    void Query() {
        
    }
}ST;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	ll t = 1;
//	cin >> t;
	while(t--) {
        cin >> n >> m;
        for(ll i = 1; i <= n; i++) cin >> a[i];
        ST.build(1,1,n);
        for(ll i = 1; i <= m; i++) {
            cin >> l;
            if(l == 1) {
                cin >> x >> y >> k;
                ST.Update(x,y,m,1,1,k);    
            }
            else if(l == 2) {
                ans = 0;
                cin >> x >> y;   
                ST.Query(1,x,y);
                cout << ans << "\n";
            }
        }
	}
	return 0;
}