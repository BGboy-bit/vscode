#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
typedef array<ll, 2> PII; // vector<PII> a(n+1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 1;

void Solve() {
    ll n, c; cin >> n >> c;
    vector<ll> a(n + 1), pre(n + 1), aft(n + 1), summ(n + 1);
    summ[0] = 0; 
    ll maxx = -1;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
        if(i == 1) a[i] += c;
        if(a[i] > maxx) {
            pre[i] = i;
            maxx = a[i];
        } else pre[i] = pre[i - 1];
        summ[i]= summ[i - 1] + a[i];
    }
    maxx = -1;
    for(ll i = n; i >= 1; i -- ) {
        if(a[i] >= maxx) {
            aft[i] = i;
            maxx = a[i];
        } else aft[i] = aft[i + 1];
    }
    for(ll i = 1; i <= n; i ++ ) {
        if(pre[i] != i || aft[i] != i) {
            if(aft[i] != i && summ[i] < a[aft[i]]) {
                cout << i;
            } else cout << i - 1;
        } else cout << 0;
        cout << " \n"[i == n];
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}