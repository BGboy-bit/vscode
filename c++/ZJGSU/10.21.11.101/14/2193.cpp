#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 1e4 + 10;
ll n, m;
ll fa[MAX];
bool f;
void init() {
    f = 0;
    for(ll i = 1; i <= n; i ++ ) fa[i] = i;
}

ll find(ll x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void Solve() {
    cin >> n >> m;
    init();
    ll x, y;
    for(ll i = 0; i < m; i ++ ) {
        cin >> x >> y;
        ll fx = find(x), fy = find(y);
        if(fx != fy) fa[fx] = fy;
    }
    ll fx = find(1);
    for(ll i = 2; i <= n; i ++ ) {
        ll fy = find(i);
        if(fy != fx) {
            cout << "no" << "\n";
            f = 1;
            break;
        }
    }
    if(!f) cout << "yes" << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}