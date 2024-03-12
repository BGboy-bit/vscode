#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 5e5 + 10;

void Solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> cnt(7,0);
    unordered_map<ll,ll> mp;
    mp[4] = 1; mp[8] = 2; mp[15] = 3; mp[16] = 4; mp[23] = 5; mp[42] = 6;  
    for(ll i = 0; i < n; i ++) {
        cin >> a[i];
        if(a[i] == 4) cnt[1] ++;
        else if(cnt[mp[a[i]] - 1] > 0) {
            cnt[mp[a[i]] - 1] --;
            cnt[mp[a[i]]] ++;
        } 
    }
    cout << n - cnt[6] * 6 << "\n";
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