#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 1;//¶à×éÊäÈë

ll n;
struct node {
    ll w; ll num;
}a[MAX];
bool cmp (node u, node v) {
    if(u.w != v.w) return u.w > v.w;
    else return u.num < v.num;
}

ll b;
void Solve() {
    cin >> n;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i].w; a[i].num = i; 
    }
    for(ll i = 1; i <= n; i ++ ) {
        cin >> b;
        a[i].w -= b;
    }
    sort(a + 1, a + n + 1, cmp);
    ll W = a[1].w; 
    vector<ll> a1;
    a1.push_back(a[1].num);
    for(ll i = 2; i <= n; i ++ ) {
        if(a[i].w != W) break;
        else a1.push_back(a[i].num);
    }
    cout << a1.size() << "\n";
    for(auto i : a1) cout << i << " ";
    cout << "\n";
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