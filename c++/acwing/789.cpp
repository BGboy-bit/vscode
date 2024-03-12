#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 1e5 + 10;
ll n,q,k;
vector<ll> a(MAX);

void bin_search() {
    ll l = 0, r = n - 1;
    while(l < r) {
        ll mid = l + r >> 1;
        if(a[mid] >= k) r = mid;
        else l = mid + 1;
    }
    if(a[l] != k) cout << "-1 -1" << "\n";
    else {
        cout << l << " ";
        ll l = 0,r = n - 1;
        while(l < r) {
            ll mid = l + r + 1 >> 1;
            if(a[mid] <= k) l = mid;
            else r = mid - 1;
        }
        cout << l << "\n";
    }
}


void Solve() {
    cin >> n >> q;
    for(ll i = 0; i < n; i ++) cin >> a[i];
    for(ll i = 0; i < q; i ++) {
        cin >> k;
        bin_search();
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    Solve();
    return 0;
}