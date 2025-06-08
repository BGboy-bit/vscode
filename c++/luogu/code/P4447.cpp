#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    vector<ll> a(n + 1); 
    map<ll, ll> mp;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
        mp[a[i]] ++ ;
    }
    sort(a.begin() + 1, a.end());
    ll ans = n + 1;
    for(ll i = 1; i <= n; i ++ ) {
        if(mp[a[i]] == 0) continue;
        mp[a[i]] -- ;
        for(ll j = a[i] + 1, cnt = 1; ; j ++ ) {
            if(!mp.count(j) || mp[j] < mp[j - 1] + 1) {
                ans = min(ans, cnt); break;  
            } else {
                cnt ++ ;
                mp[j] -- ;
            } 
        }
    }
    cout << ans << "\n";
    return 0;
}