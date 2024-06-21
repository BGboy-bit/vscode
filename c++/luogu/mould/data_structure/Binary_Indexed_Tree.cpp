#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int MAX = 5e5 + 10;
ll n,m,arr,f,x,y;

ll Lowbit(ll x) {
    return x & -x;
}

void Update(ll x,ll val,vector<ll> &c,ll n) {
    for(; x <= n; x += Lowbit(x)) c[x] += val;
}

ll Sum(ll x,vector<ll> &c,ll n) {
    ll sum = 0;
    for(; x > 0; x -= Lowbit(x)) sum += c[x];
    return sum;
}

void Solve() {
    cin >> n >> m;
    vector<ll> c(n + 1,0);
    for(ll i = 1; i <= n; i++) {
        cin >> arr;
        Update(i, arr, c, n);
    }
    for(ll i = 1;i <= m;i++) {
        cin >> f >> x >> y;
        if(f == 2) {
            cout << Sum(y, c, n) - Sum(x - 1, c, n) << "\n";
        }
        else Update(x, y, c, n);
    }
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