#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 1;//¶à×éÊäÈë


ll n,a[MAX],tmp[MAX];
ll merge_sort(ll l,ll r)
{
    if(l == r) return 0;
    ll mid = l + r >> 1;
    ll res = merge_sort(l,mid) + merge_sort(mid + 1,r);
    ll i = l,j = mid + 1,k = 0;
    while(i <= mid && j <= r)
    {
        if(a[i] <= a[j]) tmp[k++] = a[i++];
        else
        {
            res += mid - i + 1;
            tmp[k++] = a[j++];
        }
    }
    while(i <= mid) tmp[k++] = a[i++];
    while(j <= r) tmp[k++] = a[j++];
    for(ll i = 0,j = l;j <= r;i++,j++) a[j] = tmp[i];
    return res;
}

void Solve() {
    cin >> n;
    for(ll i = 1; i <= n; i ++ ) cin >> a[i];
    ll cnt = merge_sort(1, n);
    ll minn = 2, maxx = 0;
    if(cnt % 2 == 0) minn = 0;
    ll x = n;
    while(x) {
        maxx ++ ; x /= 2;
    }
    maxx = (1 << maxx) - 1;
    if(minn == 0) maxx -= 2;
    if(n == 1) cout << "0 1" << "\n";
    else cout << minn << " " << maxx << "\n"; 
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}
