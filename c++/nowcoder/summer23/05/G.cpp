#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 1e5 + 10;

ll a[MAX];
ll a1[MAX], a2[MAX], a3[MAX], a4[MAX];
ll pre1[MAX], pre2[MAX], pre3[MAX];
vector<ll> v4;

void Solve() {
    ll n, k;
    cin >> n >> k;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
        if(a[i] == 1) {
            a1[i] = a1[i - 1] + 1;
            pre1[a1[i]] = i;
            a2[i] = a2[i - 1];
            a3[i] = a3[i - 1];
        }
        else if(a[i] == 2) {
            a1[i] = a1[i - 1];
            a2[i] = a2[i - 1] + 1;
            pre2[a2[i]] = i;
            a3[i] = a3[i - 1];
        }
        else if(a[i] == 3) {
            a1[i] = a1[i - 1];
            a2[i] = a2[i - 1];
            a3[i] = a3[i - 1] + 1;
            pre3[a3[i]] = i;
        }
        else {
            a1[i] = a1[i - 1];
            a2[i] = a2[i - 1];
            a3[i] = a3[i - 1];
            v4.push_back(i);
        }
    }
    ll ans = inf;
    for(ll i = 0, j = k - 1; j < v4.size(); i ++ , j ++ ) {
        ll l = v4[i], r = v4[j];
        vector<ll> l1, r1;
        l1.push_back(l); r1.push_back(r);
        if(a1[r] - a1[l] == 0) {
            l1.push_back(pre1[a1[l]] - 1);
            r1.push_back(pre1[a1[r] + 1]);
        }
        if(a2[r] - a2[l] == 0) {
            l1.push_back(pre2[a2[l]] - 1);
            r1.push_back(pre2[a2[r] + 1]);
        }
        if(a3[r] - a3[l] == 0) {
            l1.push_back(pre3[a3[l]] - 1);
            r1.push_back(pre3[a3[r] + 1]);
        }
        for(auto l2 : l1) {
            for(auto r2 : r1) {
                if(a1[r2] - a1[l2] >= 1 && a2[r2] - a2[l2] >= 1 && a3[r2] - a3[l2] >= 1) ans = min(ans, r2 - l2 + 1);
            }
        }
    }
    cout << ans << "\n";
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