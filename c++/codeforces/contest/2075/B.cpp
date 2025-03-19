#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n + 1);
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
    } 
    if(k == 1) {
        cout << max(*max_element(a.begin() + 2, a.end()) + a[1], *max_element(a.begin() + 1, a.end() - 1) + a[n]) << "\n";
        return ;
    }
    sort(a.begin() + 1, a.end());
    cout << (ll)accumulate(a.end() - k - 1, a.end(), 0ll) << "\n";
}   

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll T = 1; cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}