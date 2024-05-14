#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 3e5 + 10;

ll n, k;
struct node {
    ll num;
    ll x;
}a[MAX];

bool cmp(node u, node v) {
    if(u.x != v.x) return u.x > v.x;
    else return u.num < v.num;
}

void Solve() {
    cin >> n >> k;
    for(ll i = 1; i <= n; i ++ ) {
        ll x;
        cin >> x;
        if(x % k == 0) x = k;
        else if(x > k) x %= k;
        a[i].num = i;
        a[i].x = x;
    }
    sort(a + 1, a + n + 1, cmp);
    for(ll i = 1; i <= n; i ++ ) cout << a[i].num << " ";
    cout << "\n"; 
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    cin >> T;
    while(T --) {
        Solve();
    }
    return 0;
}