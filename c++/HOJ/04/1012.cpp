#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 1e5 + 10;

struct node {
    ll a, b, d;
}c[MAX];
ll n;

bool cmp(node x, node y) {
    return x.d > y.d;
}

void Solve() {
    cin >> n;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> c[i].a >> c[i].b;
        c[i].d = c[i].a + c[i].b;
    }
    sort(c + 1, c + n + 1, cmp);
    ll ans1 = 0, ans2 = 0;
    for(ll i = 1; i <= n; i ++ ) {
        if(i % 2 == 1) ans1 += c[i].a;
        else ans2 += c[i].b;
    }
    cout << ans1 - ans2 << "\n";
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