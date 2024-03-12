#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int MAX = 2e5 + 10;
ll n, k;
ll a[MAX];
unordered_map<ll, ll> mp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    ll ans = 0;
    mp[0] = 1;//a[i] == 0 -> a(0 - i) is ans;
    for(ll i = 1; i <= n; i ++ ) {
        cin >> a[i];
        a[i] = (a[i] + a[i - 1] - 1) % k;
        ans += mp[a[i]];
        mp[a[i]] ++ ;
        if(i - k + 1 >= 0) mp[a[i - k + 1]] -- ; 
    }
    if(k == 1) cout << "0" << "\n";
    else cout << ans << "\n";
    return 0;
}