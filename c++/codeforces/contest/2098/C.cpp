#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve() {
    ll n; cin >> n;
    vector<ll> a(n + 1);
    map<ll, ll> mp;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
        mp[a[i]] ++ ;
    }
    sort(a.begin() + 1, a.end());
    for(ll i = 1; i <= n; i ++ ) {
        if(mp[a[i]] >= 4) {
            cout << "Yes\n"; return ;
        } else if(mp[a[i]] >= 2) {
            for(ll j = a[i] + 1; ; j ++ ) {
                if(mp[j] >= 2) {
                    cout << "Yes\n"; return ;
                } else if(mp[j] == 0) {
                    break;
                } 
                mp[j] = 0;
            }
            mp[a[i]] = 0;
        }
    }
    cout << "No\n";
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